//glad-glfw
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//windows
#include <iostream>
#include <windows.h>

//sql
#include "sql/sqlite3.h" 
#include <conio.h> // _getch()

using std::cout; using std::cin; using std::endl, std::cerr;

//OpenGl
void framebuffer_size_callback(GLFWwindow* window, int width, int height); //func for resize window
void keyLog(GLFWwindow* window);

void Erys(); //prod

//Basedata
int callback(void* NotUsed, int argc, char** argv, char** azColName);
void executeDialogue(sqlite3* db);
void printDialogueWithPause(sqlite3* db);


const int WIDTH = 1280;
const int  HEIGHT = 720;
float ke_color;

int main() {
    //Erys(); //Prod

    SetConsoleOutputCP(CP_UTF8); //ru-encoding for console
    sqlite3* db;
    int rc = sqlite3_open("C:\\Users\\132ki\\Desktop\\JLTO\\src\\sql\\storyline.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return rc;
    }

    printDialogueWithPause(db);

    sqlite3_close(db);
    return 0;

    
}

//OpenGL
void keyLog(GLFWwindow* window) { //button callback
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true); //Escape
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        ke_color += 0.001; //color
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

//Basedata
int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << (azColName[i] ? azColName[i] : "NULL") << ": " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}

void executeSQL(sqlite3* db, const char* sql, int (*callback)(void*, int, char**, char**)) {
    char* errMsg = 0;
    int rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}

void executeDialogue(sqlite3* db) {
    const char* sql = "SELECT characters.name, dialogues.dialogue_text "
        "FROM dialogues "
        "JOIN characters ON dialogues.character_id = characters.id "
        "ORDER BY dialogues.id;";
    executeSQL(db, sql, callback);
}

void printDialogueWithPause(sqlite3* db) {
    const char* sql = "SELECT characters.name, dialogues.dialogue_text "
        "FROM dialogues "
        "JOIN characters ON dialogues.character_id = characters.id "
        "ORDER BY dialogues.id;";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        cerr << "Failed to fetch data: " << sqlite3_errmsg(db) << endl;
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        const char* dialogue = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

        cout << name << ": " << dialogue << endl;

        while (_getch() != ' ') {}
    }

    sqlite3_finalize(stmt);
}
