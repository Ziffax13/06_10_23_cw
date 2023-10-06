#pragma once
#include<iostream>
#include<string.h>
using namespace std;

struct iSwim {
    virtual void Swim() = 0;
};

struct iFly {
    virtual void Fly() = 0;
};

class Animal  // абстрактный класс !!
{
protected:
    char* name;
    int kg;
public:
    Animal() = default;
    Animal(const char* n, int k)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        kg = k;
    }
    void Print()
    {
        cout << "Name: " << name << "Kg: " << kg << endl;
    }
    virtual void Continent() = 0;
    virtual void Eat() = 0;
    virtual void Sound() = 0;

    ~Animal()
    {
        delete[] name;
    }
};

class Pinguin : public Animal,  public iSwim
{
    char* continent;

public:
    Pinguin() = default;
    Pinguin(const char* n, int kg, const char* cont) :Animal(n, kg)
    {
        continent = new char[strlen(cont) + 1];
        strcpy_s(continent, strlen(cont) + 1, cont);
    }

    virtual void Eat()
    {
        cout << "Пингвины едят рыбу\n";
    }
    virtual void Sound()
    {
        cout << "Пингвины издают какие то звуки\n";
    }
    virtual void Continent()
    {
        cout << "Пингвины живут в Антарктиде\n";
    }

    virtual  void Swim()
    {
        cout << "Пингвины отлично плавают\n";
    }
    virtual  void Fly()
    {
        cout << "Пингвины отлично летают???? Ой не знаю))))\n";
    }
    ~Pinguin()
    {
        delete[] continent;
    }
};


class Parrot : public Animal, public iFly
{
    char* continent;

public:
    Parrot() = default;
    Parrot(const char* n, int kg, const char* cont) :Animal(n, kg)
    {
        continent = new char[strlen(cont) + 1];
        strcpy_s(continent, strlen(cont) + 1, cont);
    }

    virtual void Eat()
    {
        cout << "Попугаи едят\n";
    }
    virtual void Sound()
    {
        cout << "Попугаи издают какие то звуки\n";
    }
    virtual void Continent()
    {
        cout << "Попугаи живут на континенте\n";
    }

    virtual  void Swim()
    {
        cout << "Попугаи не плавают\n";
    }
    virtual  void Fly()
    {
        cout << "Попугаи отлично летают\n";
    }
    ~Parrot()
    {
        delete[] continent;
    }
};
