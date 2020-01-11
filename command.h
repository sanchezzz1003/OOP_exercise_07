#ifndef COMMAND_H
#define COMMAND_H 1

#include "document.h"
#include <stack>

class Command {
protected:
    std::shared_ptr<Document> Doc;
public:
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
    virtual ~Command() = default;

    void SetDocument(std::shared_ptr<Document> doc) {
        Doc = doc;
    }
};

class InsertCommand : public Command {
public:
    InsertCommand(FigureType type, Vertex *vertices) :
            Type{type}, Vertices{vertices} {};

    void Execute() override {
        Doc->InsertPrimitive(Type, Vertices);
    }

    void UnExecute() override {
        Doc->RemoveLastPrimitive();
    }

private:
    FigureType Type;
    Vertex *Vertices;
};


class RemoveCommand : public Command {
public:
    RemoveCommand(int id) : Id(id), Pos(0), figure(nullptr) {};

    void Execute() override {

        figure = Doc->GetFigure(Id);
        if (figure == nullptr) {
            std::cout << "ERROR\n";
            return;
        }
        Pos = Doc->GetPos(Id);
        if (Pos == 0) {
            std::cout << "ERROR\n";
            return;
        }
        Doc->RemovePrimitive(Id);
    }

    void UnExecute() override {
        Doc->InsertPrimitive(Pos, figure);
    }

private:
    int Id;
    int Pos;
    std::shared_ptr<Figure> figure;
};

#endif //COMMAND_H
