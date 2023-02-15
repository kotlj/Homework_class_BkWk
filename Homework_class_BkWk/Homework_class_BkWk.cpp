
#include <iostream>
#include <conio.h>

class Book
{
private:
    char* author;
    char* name;
    char* publishHouse;
    unsigned int year;
    unsigned int numPages;

public:
    Book()
    {
        author = new char[2]; author[0] = 'A'; author[1] = '\0';
        name = new char[2]; name[0] = '1'; name[1] = '\0';
        publishHouse = new char[3]; publishHouse[0] = 'F'; publishHouse[1] = '0'; publishHouse[2] = '\0';
        year = 2000;
        numPages = 300;
    }
    Book(char* _author, char* _name, char* _publishHouse, int _year, int _numPages)
    {
        setAuthor(_author);
        setName(_name);
        setPublishHouse(_publishHouse);
        this->year = _year;
        this->numPages = _numPages;
    }
    explicit Book(char* _name)
    {
        setName(_name);
        char* tample = new char[2]; tample[0] = 'n'; tample[1] = '\0';
        setAuthor(tample);
        setPublishHouse(tample);
        year = 2000;
        numPages = 300;
    }



    char* getAuthor() const
    {
        return author;
    }
    char* getName() const
    {
        return name;
    }
    char* getPublishHouse() const
    {
        return publishHouse;
    }
    int getYear() const
    {
        return year;
    }
    int getPages() const
    {
        return numPages;
    }

    void setAuthor(char* _author)
    {
        int len = strlen(_author);
        if (author != nullptr)
        {
            delete[] author;
        }
        this->author = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            this->author[i] = _author[i];
        }
        this->author[len] = '\0';
    }
    void setName(char* _name)
    {
        int len = strlen(_name);
        if (name != nullptr)
        {
            delete[] name;
        }
        this->name = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            this->name[i] = _name[i];
        }
        this->name[len] = '\0';
    }
    void setPublishHouse(char* _publishHouse)
    {
        int len = strlen(_publishHouse);
        if (publishHouse != nullptr)
        {
            delete[] publishHouse;
        }
        this->publishHouse = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            this->publishHouse[i] = _publishHouse[i];
        }
        this->publishHouse[len] = '\0';
    }
    void setYear(int _year)
    {
        this->year = _year;
    }
    void setPages(int _numPages)
    {
        this->numPages = _numPages;
    }

    ~Book()
    {
        delete[] author;
        delete[] name;
        delete[] publishHouse;
    }
};

void showBook(Book &obj)
{
    std::cout << "--------------------" << "\nName: " << obj.getName() << "\nAuthor: " << obj.getAuthor()
        << "\nPublishing house: " << obj.getPublishHouse() << "\nYear: " << obj.getYear() << "\nNumber of pages: "
        << obj.getPages() << '\n';
}
void findByAuthor(Book*& obj, int size, char* _author)
{
    int indx_1 = 0;
    bool equal = true;
    for (indx_1 = 0; _author[indx_1] != '\0'; indx_1++);
    int indx_2 = 0;
    char* tample;
    for (int i = 0; i < size; i++)
    {
        tample = obj[i].getAuthor();
        for (indx_2 = 0; tample[indx_2] != '\0'; indx_2++);
        if (indx_1 == indx_2)
        {
            for (int j = 0; j < indx_1 + 1; j++)
            {
                if (_author[j] != tample[j])
                {
                    equal = false;
                    break;
                }
            }
        }
        else
        {
            equal = false;
        }
        if (equal)
        {
            showBook(obj[i]);
        }
    }
}
void findByPubHouse(Book* &obj, int size, char* _publishHouse)
{
    int indx_1 = 0;
    bool equal = true;
    for (indx_1 = 0; _publishHouse[indx_1] != '\0'; indx_1++);
    int indx_2 = 0;
    char* tample;
    for (int i = 0; i < size; i++)
    {
        tample = obj[i].getPublishHouse();
        for (indx_2 = 0; tample[indx_2] != '\0'; indx_2++);
        if (indx_1 == indx_2)
        {
            for (int j = 0; j < indx_1 + 1; j++)
            {
                if (_publishHouse[j] != tample[j])
                {
                    equal = false;
                    break;
                }
            }
        }
        else
        {
            equal = false;
        }
        if (equal)
        {
            showBook(obj[i]);
        }
    }
}
void findByYear(Book* &obj, int size, int _year)
{
    for (int i = 0; i < size; i++)
    {
        if (obj[i].getYear() == _year);
        {
            showBook(obj[i]);
        }
    }
}

class Worker
{
private:
    char* fullName;
    char* post;
    int year;
    float payment;

public:
    Worker()
    {
        fullName = new char[2]; fullName[0] = 'n'; fullName[1] = '\0';
        post = new char[2]; post[0] = 'n'; post[1] = '\0';
        year = time(0) / 31536000;
        payment = 0;
    }
    Worker(char* _fullName, char* _post, int _year, float _payment)
    {
        setFullName(_fullName);
        setPost(_post);
        year = _year;
        payment = _payment;
    }
    explicit Worker(char* _fullName)
    {
        setFullName(_fullName);
        char* tample = new char[2]; tample[0] = 'n'; tample[1] = '\0';
        setPost(tample);
        year = time(0) / 31536000;
        payment = 0;
    }

    char* getFullName() const
    {
        return fullName;
    }
    char* getPost() const
    {
        return post;
    }
    int getYear() const
    {
        return year;
    }
    float getPayment() const
    {
        return payment;
    }

    void setFullName(char* _fullName)
    {
        int size = strlen(_fullName);
        if (fullName != nullptr)
        {
            delete[] fullName;
        }
        this->fullName = new char[size + 1]; fullName[size] = '\0';
        for (int i = 0; i < size; i++)
        {
            this->fullName[i] = _fullName[i];
        }
    }
    void setPost(char* _post)
    {
        int size = strlen(_post);
        if (post != nullptr)
        {
            delete[] post;
        }
        this->post = new char[size + 1]; post[size] = '\0';
        for (int i = 0; i < size; i++)
        {
            this->post[i] = _post[i];
        }
    }
    void setYear(int _year)
    {
        this->year = _year;
    }
    void setPayment(float _payment)
    {
        this->payment = _payment;
    }

    ~Worker()
    {
        delete[] fullName;
        delete[] post;
    }
};

void showWorker(Worker &obj)
{
    std::cout << "-----------------------" << "\nFull name: " << obj.getFullName() << "\nPost: " << obj.getPost()
        << "\nYear of hire: " << obj.getYear() << "\nPayment: " << obj.getPayment() << "\n";
}
void findByExperience(Worker* &arr, int size, int _experience)
{
    for (int i = 0; i < size; i++)
    {
        if (time(0) / 31536000 - arr[i].getYear() > _experience)
        {
            showWorker(arr[i]);
        }
    }
}
void findByPayment(Worker* arr, int size, int _payment)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].getPayment() > _payment)
        {
            showWorker(arr[i]);
        }
    }
}
void findByPost(Worker* arr, int size, char* _post)
{
    bool equal = true;
    char* tample = nullptr;
    for (int i = 0; i < size; i++)
    {
        tample = arr[i].getPost();
        equal = true;
        if (strlen(tample) == strlen(_post))
        {
            for (int j = 0; j < strlen(_post); j++)
            {
                if (tample[j] != _post[j])
                {
                    equal = false;
                }
            }
        }
        else
        {
            equal = false;
        }
        if (equal)
        {
            showWorker(arr[i]);
        }
    }
}

int main()
{
    int choise = 1;
    int arrSize = 3;
    int ptrCharSize = 3;
    //Book prepare:
    char* _author = new char[ptrCharSize]; _author[ptrCharSize - 1] = '\0';
    char* _name = new char[ptrCharSize]; _name[ptrCharSize - 1] = '\0';
    char* _publishHouse = new char[ptrCharSize]; _publishHouse[ptrCharSize - 1] = '\0';
    Book* bookArr = new Book[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        _author[0] = 'a' + i % 3; _author[1] = 'a' + i % 3;
        bookArr[i].setAuthor(_author);
        _name[0] = '1' + i % 3; _name[1] = '1' + i % 3;
        bookArr[i].setName(_name);
        _publishHouse[0] = 'a' + i % 3; _publishHouse[1] = '1' + i % 3;
        bookArr[i].setPublishHouse(_publishHouse);
        bookArr[i].setPages(100 * i);
        bookArr[i].setYear(1850 + 12 * i);
    }
    //Worker prepare:
    Worker* workerArr = new Worker[arrSize];
    char* _fullName = new char[ptrCharSize]; _fullName[ptrCharSize - 1] = '\0';
    char* _post = new char[ptrCharSize]; _post[ptrCharSize - 1] = '\0';
    for (int i = 0; i < arrSize; i++)
    {
        _fullName[0] = char('a' + i); _fullName[1] = char('a' + i);
        workerArr[i].setFullName(_fullName);
        _post[0] = 'a'; _post[1] = char('0' + i);
        workerArr[i].setPost(_post);
        workerArr[i].setYear(i);
        workerArr[i].setPayment(float(i + i / 10));
    }
    while (choise != 0)
    {
        std::cout << "Choose:\n1 - Book array;\n2 - Worker array;\n0 - exit;\n";
        std::cin >> choise;
        if (choise == 1)
        {
            char* tample = new char[ptrCharSize]; tample[ptrCharSize - 1] = '\0';
            char key = ' ';
            std::cout << "\n1 - find by author;\n2 - find by publishing house;\n3 - find by year;\n";
            std::cin >> choise;
            for (int i = 0; i < arrSize; i++)
            {
                showBook(bookArr[i]);
            }
            if (choise == 1)
            {
                std::cout << "Enter author:\n";
                for (int i = 0; i < ptrCharSize - 1; i++)
                {
                    key = _getch();
                    std::cout << key;
                    tample[i] = key;
                }
                std::cout << '\n';
                findByAuthor(bookArr, arrSize, tample);
            }
            else if (choise == 2)
            {
                std::cout << "Enter publish house:\n";
                for (int i = 0; i < ptrCharSize - 1; i++)
                {
                    key = _getch();
                    std::cout << key;
                    tample[i] = key;
                }
                std::cout << '\n';
                findByPubHouse(bookArr, arrSize, tample);
            }
            else if (choise == 3)
            {
                int year = 0;
                std::cout << "Enter year:\n";
                std::cin >> year;
                findByYear(bookArr, arrSize, year);
            }
            choise = 1;
            delete[] tample;
        }
        else if (choise == 2)
        {
            std::cout << "\n1 - find by expirience;\n2 - find by payment;\n3 - find by post;\n";
            std::cin >> choise;
            for (int i = 0; i < arrSize; i++)
            {
                showWorker(workerArr[i]);
            }
            if (choise == 1)
            {
                int exp = 0;
                std::cout << "Enter expirience:\n";
                std::cin >> exp;
                findByExperience(workerArr, arrSize, exp);
            }
            else if (choise == 2)
            {
                float payment = 0.0;
                std::cout << "Enter payment:\n";
                std::cin >> payment;
                findByPayment(workerArr, arrSize, payment);
            }
            else if (choise == 3)
            {
                char* tample = new char[ptrCharSize]; tample[ptrCharSize - 1] = '\0';
                char key = ' ';
                std::cout << "Enter post:\n";
                for (int i = 0; i < ptrCharSize - 1; i++)
                {
                    key = _getch();
                    std::cout << key;
                    tample[i] = key;
                }
                std::cout << '\n';
                findByPost(workerArr, arrSize, tample);
                delete[] tample;
            }
            choise = 2;
        }
    }
    delete[] _author;
    delete[] _name;
    delete[] _publishHouse;
    delete[] _fullName;
    delete[] _post;
}