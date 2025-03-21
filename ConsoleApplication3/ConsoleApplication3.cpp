#include <iostream>
#include <cstdio>

using namespace std;

struct User
{
    char* name;
    char* surname;
    int age;
};

void CreateUser(User*& user)
{
    user = new User;
    user->name = new char[50];
    user->surname = new char[50];

    cout << "Enter name : ";
    cin >> user->name;

    cout << "Enter surname : ";
    cin >> user->surname;

    cout << "Enter age : ";
    cin >> user->age;
}

void Save(User* user)
{
    FILE* file;

    fopen_s(&file, "C:\\Users\\onurb\\OneDrive\\Belgeler - Köçür\\Masaüstü\\New Text Document.txt", "w");
    if (file)
    {
        fprintf(file, "%s\n", user->name);
        fprintf(file, "%s\n", user->surname);
        fprintf(file, "%d\n", user->age);
        fclose(file);
    }

    fopen_s(&file, "C:\\Users\\onurb\\OneDrive\\Belgeler - Köçür\\Masaüstü\\New Text Document.txt", "r");
    if (file)
    {
        int size = 1024;
        char* name = new char[size];
        char* surname = new char[size];
        char* age = new char[size];

        fgets(name, size, file);
        fgets(surname, size, file);
        fgets(age, size, file);

        cout << "\n\n";

        cout << "Name : " << name << endl;
        cout << "Surname : " << surname << endl;
        cout << "Age : " << age << endl;


        fclose(file);
    }
}

int* RandomFillArray(int size)
{
    int* new_array = new int[size];

    for (int i = 0; i < size; i++)
    {
        new_array[i] = rand() % 101;
    }

    return new_array;
}

void SaveArray(int* arr, int size)
{
    FILE* file;
    const char* file_ = "C:\\Users\\onurb\\OneDrive\\Belgeler - Köçür\\Masaüstü\\New Text Document (2).txt";

    fopen_s(&file, file_, "w");
    if (file)
    {
        fwrite(arr, sizeof(int), size, file);
        fclose(file);
    }

    fopen_s(&file, file_, "r");
    if (file)
    {
        int* buffer = new int[size];
        fread(buffer, sizeof(int), size, file);

        cout << "\n";

        cout << "Array : ";

        for (int i = 0; i < size; i++)
        {
            cout << buffer[i] << " ";
        }
        cout << endl;
        fclose(file);
    }
}

void main()
{
    cout << "--------------------------";
    cout << "\n\n";
    cout << "Tap - 1";
    cout << "\n\n";

    User* user = nullptr;
    CreateUser(user);
    Save(user);

    cout << "\n\n";
    cout << "--------------------------";
    cout << "\n\n";
    cout << "Tap - 2";
    cout << "\n\n";

    srand(time(NULL));

    int size;

    cout << "Enter size : ";
    cin >> size;

    int* array = RandomFillArray(size);
    SaveArray(array, size);

    cout << "\n\n";
    cout << "--------------------------";
}
