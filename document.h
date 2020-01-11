#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <fstream>
#include <list>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <utility>
#include "figures.h"
#include "factory.h"

class Document {
public:
    Document() : Id(1), Name(""), Buffer(0), factory() {};

    Document(std::string name) : Id(1), Name(name), Buffer(0), factory() {};

    ~Document() = default;

    void Rename(const std::string &newName) {
        Name = newName;
    }

    void Save(const std::string &filename) {
        SerialiseImpl(filename);
    }

    void Load(const std::string &filename) {
        DeserializeImpl(filename);
    }

    void Print() {
        std::for_each(Buffer.begin(), Buffer.end(), [](std::shared_ptr<Figure> shape) {
            shape->Print(std::cout) << "\n";
        });
    }

    void RemovePrimitive(int id) {
        auto it = std::find_if(Buffer.begin(), Buffer.end(),
                [id](std::shared_ptr<Figure> shape) -> bool {
            return id == shape->getId();
        });

        if (it == Buffer.end()) {
            throw std::logic_error("Figure with this id doesn't exist");
        }

        Buffer.erase(it);
    }

    void InsertPrimitive(FigureType type, Vertex *vertices) {
        switch (type) {
            case Pent:
                Buffer.push_back(factory.FigureCreate(Pent,vertices, Id));
                break;
            case Rhomb:
                Buffer.push_back(factory.FigureCreate(Rhomb, vertices, Id));
                break;
            case Trapeze:
                Buffer.push_back(factory.FigureCreate(Trapeze, vertices, Id));
                break;
        }
        Id++;
    }

private:
    int Id;
    std::string Name;
    std::list<std::shared_ptr<Figure>> Buffer;
    Factory factory;
    /*TriangleFactory triangleFactory;
	SquareFactory squareFactory;
	PentagonFactory PentagonFactory;*/

    friend class InsertCommand;
    friend class RemoveCommand;

    void SerialiseImpl(const std::string &filename) const {
        std::ofstream os(filename, std::ios::binary | std::ios::out);
        if(!os) {
            throw std::runtime_error("File is not opened");
        }
        size_t nameLen = Name.size();
        os.write((char *) &nameLen, sizeof(nameLen)); //пишем длину имени(при чтении нужно это)
        os.write((char *) Name.c_str(), nameLen); //пишем само имя c_str перевол в массив char имя
        for (const auto &shape : Buffer) {
            shape->Serialize(os);
        }
    }

    void DeserializeImpl(const std::string &filename) {
        std::ifstream is(filename, std::ios::binary | std::ios::in);
        if(!is) {
            throw std::runtime_error("File is not opened");
        }
        size_t nameLen;
        is.read((char *) &nameLen, sizeof(nameLen));  //прочли длину имени
        char *name = new char[nameLen + 1]; //создали имя такой то длины
        name[nameLen] = 0;
        is.read(name, nameLen);
        Name = std::string(name);
        delete [] name;
        FigureType type;
        while (true) {
            is.read((char *) &type, sizeof(type));
            if (is.eof()) {
                break;
            }
            switch (type) {
                case Pent:
                    Buffer.push_back(factory.FigureCreate(Pent));
                    break;
                case Rhomb:
                    Buffer.push_back(factory.FigureCreate(Rhomb));
                    break;
                case Trapeze:
                    Buffer.push_back(factory.FigureCreate(Trapeze));
                    break;
            }

            Buffer.back()->Deserialize(is);
        }
        Id = Buffer.size();
    }

    std::shared_ptr<Figure> GetFigure(int id) {
        for (auto it = Buffer.begin(); it != Buffer.end(); it++) {
            if (id == (*it)->getId()) {
                return *it;
            }
        }
        return nullptr;
    }

    int GetPos(int id) {
        int i = 0;
        for (auto it = Buffer.begin(); it != Buffer.end(); it++) {
            if (id == (*it)->getId()) {
                return i;
            }
            i++;
        }
        return -1;
    }

    void InsertPrimitive(int pos, std::shared_ptr<Figure> figure) {
        auto it = Buffer.begin();
        std::advance(it,pos);
        Buffer.insert(it,figure);
    }

    void RemoveLastPrimitive() {
        if (Buffer.empty()) {
            throw std::logic_error("Document is empty");
        }
        Buffer.pop_back();
    }

};

#endif //DOCUMENT_H