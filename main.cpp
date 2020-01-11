#include <iostream>
#include <string>
#include "editor.h"


void menu() {
    std::cout << "\nMenu\n";
    std::cout << "Create[Create] new file\n";
    std::cout << "Load\n";
    std::cout << "Save <fileName>\n";
    std::cout << "Add <figureType>\n";
    std::cout << "Remove <figure ID>\n";
    std::cout << "Undo\n";
    std::cout << "Print\n";
    std::cout << "Exit\n\n";
}

void create(Editor &editor) {
    std::string cmd;
    if (editor.DocumentExist()) {
        std::cout << "Save old document or don't save? Yes/No\n";
        std::cin >> cmd;
        if (cmd == "Yes") {
            std::string filename;
            std::cout << "Enter name of file\n";
            std::cin >> filename;
            try {
                editor.SaveDocument(filename);
                std::cout << "Document save in file " << filename << "\n";
            } catch (std::runtime_error &err) {
                std::cout << err.what() << "\n";
            }
        }
    }
    std::cout << "Enter name of new project\n";
    std::cin >> cmd;
    editor.CreateDocument(cmd);
    std::cout << "Document " << cmd << " is created\n";
}

void save(Editor &editor) {
    if (!editor.DocumentExist()) {
        throw std::runtime_error("Document does not exist");
    }
    std::string filename;
    std::cin >> filename;

    try {
        editor.SaveDocument(filename);
        std::cout << "Document save in file " << filename << "\n";
    } catch (std::runtime_error &err) {
        std::cout << err.what() << "\n";
    }
}

void load(Editor &editor) {
    std::string cmd;
    std::string filename;
    if (editor.DocumentExist()) {
        std::cout << "Save old document or don't save? Yes/No\n";
        std::cin >> cmd;
        if (cmd == "Yes") {
            std::cout << "Enter name of file\n";
            std::cin >> filename;
            try {
                editor.SaveDocument(filename);
                std::cout << "Document save in file " << filename << "\n";
            } catch (std::runtime_error& err) {
                std::cout << err.what() << "\n";
            }
        }
        std::cout << "Enter the name of the file to upload:\n";
        std::cin >> filename;
        try {
            editor.LoadDocument(filename);
            std::cout << "Document loaded from file " << filename << "\n";
        } catch (std::runtime_error& err) {
            std::cout << err.what() << "\n";
        }
    }
}

void add(Editor &editor) {
    if (!editor.DocumentExist()) {
        throw std::runtime_error("Document does not exist");
    }
    std::string type;
    std::cout << "Enter shape type: Pentagon[Pent], Trapezoid[Trapeze] or Rhombus[Rhomb].\n";
    std::cin >> type;
    if (type == "Pent") {
        Vertex *vertices = new Vertex[5];
        std::cout << "Enter the coordinates separated by a space\n";
        for (int i = 0; i< 5; i++) {
            std::cin >> vertices[i];
        }
        try {
            editor.InsertPrimitive(Pent, vertices);
            delete [] vertices;
            vertices = nullptr;
        } catch (std::logic_error &err) {
            std::cout << err.what() << "\n";
            delete [] vertices;
            vertices = nullptr;
            return;
        }
        std::cout << "Primitive is added\n";
    }
    else if (type == "Trapeze") {
        Vertex *vertices = new Vertex[4];
        std::cout << "Enter the coordinates separated by a space\n";
        for (int i = 0; i < 4; i++) {
            std::cin >> vertices[i];
        }
        try {
            editor.InsertPrimitive(Trapeze, vertices);
            delete [] vertices;
            vertices = nullptr;
        } catch (std::logic_error &err) {
            std::cout << err.what() << "\n";
            delete [] vertices;
            vertices = nullptr;
            return;
        }
        std::cout << "Primitive is added\n";
    }
    else if (type == "Rhomb") {
        Vertex *vertices = new Vertex[4];
        std::cout << "Enter the coordinates separated by a space\n";
        for (int i = 0; i < 4; i++) {
            std::cin >> vertices[i];
        }
        try {
            editor.InsertPrimitive(Rhomb, vertices);
            delete [] vertices;
            vertices = nullptr;
        } catch (std::logic_error &err) {
            std::cout << err.what() << "\n";
            delete [] vertices;
            vertices = nullptr;
            return;
        }
        std::cout << "Primitive is added\n";
    }
    else {
        std::cout << "Primitive isn't added\n";
        return;
    }
}

void remove(Editor &editor) {
    if (!editor.DocumentExist()) {
        std::cout << "Document does not exist\n";
    }
    int id;
    std::cin >> id;
    if (id <= 0) {
        std::cout << "Invalid id\n";
        return;
    }
    try {
        editor.RemovePrimitive(id);
    } catch (std::exception &e) {
        std::cout << "Invalid id\n";
        return;
    }
    std::cout << "Remove primitive at id: " << id << "\n";
}



int main() {
    Editor editor;
    std::string cmd = "Menu";

    while(cmd != "Ex") {
        if (cmd == "Menu") {
            menu();
        }
        else if (cmd == "Create") {
            create(editor);
        }
        else if (cmd == "Save") {
            try {
                save(editor);
            } catch (std::runtime_error &err) {
            }
        }
        else if (cmd == "Load") {
            try {
                load(editor);
            } catch (std::runtime_error &err) {
                std::cout << err.what() << "\n\n";
            }
        }
        else if (cmd == "Add") {
            try {
                add(editor);
            } catch (std::runtime_error &err) {
                std::cout << err.what() << "\n\n";
            }
        }
        else if (cmd == "Remove") {
            try {
                remove(editor);
            } catch (std::exception &err) {
                std::cout << err.what() << "\n";
            }
        }
        else if (cmd == "Undo") {
            try {
                editor.Undo();
                std::cout << "OK\n";
            } catch (std::logic_error &err) {
                std::cout << err.what() << "\n\n";
            }
        }
        else if (cmd == "Print") {
            if (!editor.DocumentExist()) {
                std::cout << "Document does not exist" << "\n\n";
                continue;
            }
            editor.PrintDocument();
        }
        else if(cmd == "Exit"){
            return 0;
        } else {
            std::cout << "You did not choose an action\n";
        }
        std::cin >> cmd;
        std::cout << "\n";
    }
    return 0;
}
