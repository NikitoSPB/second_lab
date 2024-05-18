#include <iostream>
#include <chrono>
#include "massiv.cpp"
#define CountElementsCheckTimeList 10

using namespace std;
using namespace chrono;

struct tList
{
    int value;
    tList* next = NULL;
    tList* prev = NULL;
};

void printList(tList* pLhead)
{
    tList* pLtemp = pLhead;
    cout << "\nForward list:\n";
    for (int i = 0; pLtemp->next != NULL; i++)
    {
        cout << pLtemp->value << " -> ";
        pLtemp = pLtemp->next;
    }
    cout << pLtemp->value;
    cout << "\nReverse list:\n";
    for (int i = 0; pLtemp->prev != NULL; i++)
    {
        cout << pLtemp->value << " <- ";
        pLtemp = pLtemp->prev;
    }
    cout << pLtemp->value;
    cout << '\n';
}

tList* deleteList(tList* dLhead)
{
    if (dLhead->next == NULL)
        return dLhead;
    tList* temp = dLhead;
    dLhead = dLhead->next;
    while (dLhead->next != NULL)
    {
        temp->next = NULL;
        dLhead->prev = NULL;
        delete temp;
        temp = dLhead;
        dLhead = dLhead->next;
    }
    temp->next = NULL;
    dLhead->prev = NULL;
    delete temp;
    return dLhead;
}

void createTList(tList* cTLhead, int cTLlength)
{
    tList* cTLtemp = cTLhead;
    cTLtemp->value = rand() % 100;
    for (int i = 1; i < cTLlength; i++)
    {
        tList* elem = new tList;
        elem->value = rand() % 100;
        elem->prev = cTLtemp;
        cTLtemp->next = elem;
        cTLtemp = cTLtemp->next;
    }
    cout << "List created successfully.\n";
    printList(cTLhead);
    system("Pause");
}

void createTList2(tList* cTL2head)
{
    tList* cTL2temp = cTL2head;
    cout << "Enter elements of list\n";
    cin >> cTL2temp->value;
    while (cin.get() != '\n')
    {
        tList* elem = new tList;
        cin >> elem->value;
        elem->prev = cTL2temp;
        cTL2temp->next = elem;
        cTL2temp = cTL2temp->next;
    }
    cout << "List created successfully.\n";
    printList(cTL2head);
    system("Pause");
}

void createTListTime(int cTLTlength)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    tList* cTLThead = new tList;
    tList* cTLTtemp = cTLThead;
    start = steady_clock::now();
    cTLTtemp->value = rand() % 100;
    for (int i = 1; i < cTLTlength; i++)
    {
        tList* elem = new tList;
        elem->value = rand() % 100;
        elem->prev = cTLTtemp;
        cTLTtemp->next = elem;
        cTLTtemp = cTLTtemp->next;
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << '\n';
    printList(cTLThead);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
    cTLThead = deleteList(cTLThead);
    delete cTLThead;
}

void createTListTime2()
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    tList* cTLT2head = new tList;
    tList* cTLT2temp = cTLT2head;
    cout << "Enter elements of list\n";
    cin >> cTLT2temp->value;
    start = steady_clock::now();
    while (cin.get() != '\n')
    {
        tList* elem = new tList;
        cin >> elem->value;
        elem->prev = cTLT2temp;
        cTLT2temp->next = elem;
        cTLT2temp = cTLT2temp->next;
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << '\n';
    printList(cTLT2head);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
    cTLT2head = deleteList(cTLT2head);
    delete cTLT2head;
}

void addList(tList* aLhead, int aLvalue, int aLpos)
{
    tList* elem = new tList;
    elem->value = aLvalue;
    if (aLpos == 0)
    {
        elem->next = aLhead;
        aLhead->prev = elem;
        aLhead = aLhead->prev;
    }
    else
    {
        tList* aLtemp = aLhead;
        int i = 1;
        for (i; i != aLpos && aLtemp->next != NULL; i++)
            aLtemp = aLtemp->next;
        if (i == aLpos && aLtemp->next == NULL)
        {
            elem->prev = aLtemp;
            aLtemp->next = elem;
        }
        else if (i == aLpos && aLtemp->next != NULL)
        {
            elem->next = aLtemp->next;
            elem->prev = aLtemp;
            aLtemp->next = elem;
            aLtemp = aLtemp->next;
            aLtemp = aLtemp->next;
            aLtemp->prev = elem;
        }
        else
        {
            cout << "Count of elements in list less, than position. Error!\n";
            return;
        }
    }
    cout << "Element add successfully.\n";
    printList(aLhead);
    system("Pause");
}

void deleteElemValueList(tList* dEVLhead, int dEVLnumber)
{
    tList* dEVLtemp = dEVLhead;
    tList* dEVLtemp2;
    if (dEVLtemp->value == dEVLnumber && dEVLtemp->next == NULL)
        delete dEVLtemp;
    else if (dEVLtemp->value == dEVLnumber && dEVLtemp->next != NULL)
    {
        dEVLtemp2 = dEVLtemp->next;
        dEVLtemp->next = NULL;
        dEVLtemp2->prev = NULL;
        delete dEVLtemp;
    }
    else if (dEVLtemp->value != dEVLnumber)
    {
        while (dEVLtemp->value != dEVLnumber && dEVLtemp->next != NULL)
            dEVLtemp = dEVLtemp->next;
        if (dEVLtemp->value == dEVLnumber && dEVLtemp->next == NULL)
        {
            dEVLtemp2 = dEVLtemp->prev;
            dEVLtemp2->next = NULL;
            dEVLtemp->prev = NULL;
            delete dEVLtemp;
        }
        else if (dEVLtemp->value == dEVLnumber && dEVLtemp->next != NULL)
        {
            dEVLtemp2 = dEVLtemp->prev;
            dEVLtemp2->next = dEVLtemp->next;
            dEVLtemp2 = dEVLtemp2->next;
            dEVLtemp2->prev = dEVLtemp->prev;
            dEVLtemp->prev = NULL;
            dEVLtemp->next = NULL;
            delete dEVLtemp;
        }
        else if (dEVLtemp->value != dEVLnumber)
        {
            cout << "Element not found. Error!\n";
            return;
        }
    }
    cout << "Element delete successfully.\n";
    printList(dEVLhead);
    system("Pause");
}

void deleteElemIndexList(tList* dEILhead, int dEILposition)
{
    tList* DEILtemp = dEILhead;
    if (dEILposition == 0)
    {
        dEILhead = dEILhead->next;
        DEILtemp->next = NULL;
        dEILhead->prev = NULL;
        delete DEILtemp;
    }
    else
    {
        tList* DEILtemp2 = DEILtemp->next;
        int i = 0;
        for (i; i != dEILposition && DEILtemp->next != NULL; i++)
            DEILtemp = DEILtemp->next;
        if (i == dEILposition && DEILtemp->next == NULL)
        {
            DEILtemp2 = DEILtemp;
            DEILtemp = DEILtemp->prev;
            DEILtemp2->prev = NULL;
            DEILtemp->next = NULL;
            delete DEILtemp2;
        }
        else if (i == dEILposition && DEILtemp->next != NULL)
        {
            DEILtemp2 = DEILtemp;
            DEILtemp = DEILtemp->prev;
            DEILtemp->next = DEILtemp2->next;
            DEILtemp2->next = NULL;
            DEILtemp = DEILtemp->next;
            DEILtemp->prev = DEILtemp2->prev;
            DEILtemp2->prev = NULL;
            delete DEILtemp2;
        }
        else
        {
            cout << "Element not found. Error!\n";
            return;
        }
    }
    cout << "Element delete successfully.\n";
    printList(dEILhead);
    system("Pause");
}

void swapElemList(tList* sELhead, int sELelem1, int sELelem2)
{
    if (sELelem1 == sELelem2)
    {
        cout << "Same index.Error!\n";
        system("Pause");
        return;
    }
    if (sELelem1 > sELelem2)
        swap(sELelem1, sELelem2);
    tList* firstElem = sELhead,* secondElem = sELhead;
    for (int i = 0; i != sELelem2 && (firstElem->next != NULL || secondElem->next != NULL); i++)
    {
        if (i < sELelem1)
        {
            firstElem = firstElem->next;
        }
        secondElem = secondElem->next;
    }
    swap(firstElem->value, secondElem->value);
    cout << "Element swap successfully.\n";
    printList(sELhead);
    system("Pause");
}

void getElemValueList(tList* gEVLhead, int gEVLnumber)
{
    int pos = 1;
    tList* gEVLtemp = gEVLhead;
    while (gEVLtemp->value != gEVLnumber && gEVLtemp->next != NULL)
    {
        gEVLtemp = gEVLtemp->next;
        pos++;
    }
    if (gEVLtemp->value == gEVLnumber)
        cout << "Element was found. Position " << pos - 1 << '\n';
    else
        cout << "Element not found.\n";
}

void getElemIndexList(tList* gEILhead, int gEILposition)
{
    int pos = gEILposition;
    tList* gEILtemp = gEILhead;
    while (pos != 0 && gEILtemp->next != NULL)
    {
        gEILtemp = gEILtemp->next;
        pos--;
    }
    if (pos == 0)
        cout << "Element was found. Position " << gEILposition << ". Value: " << gEILtemp->value << ".\n";
    else
        cout << "Element not found.\n";
}

void addListTime(tList* aLhead, int aLvalue, int aLpos)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    tList* elem = new tList;
    elem->value = aLvalue;
    if (aLpos == 0)
    {
        elem->next = aLhead;
        aLhead->prev = elem;
        aLhead = aLhead->prev;
    }
    else
    {
        tList* aLtemp = aLhead;
        int i = 1;
        for (i; i != aLpos && aLtemp->next != NULL; i++)
            aLtemp = aLtemp->next;
        if (i == aLpos && aLtemp->next == NULL)
        {
            elem->prev = aLtemp;
            aLtemp->next = elem;
        }
        else if (i == aLpos && aLtemp->next != NULL)
        {
            elem->next = aLtemp->next;
            elem->prev = aLtemp;
            aLtemp->next = elem;
            aLtemp = aLtemp->next;
            aLtemp = aLtemp->next;
            aLtemp->prev = elem;
        }
        else
        {
            cout << "Count of elements in list less, than position. Error!\n";
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "Time: ";
            cout << result.count();
            cout << " ns\n\n";
            return;
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << '\n';
    cout << "Element add successfully.\n";
    printList(aLhead);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
}

void deleteElemValueListTime(tList* dEVLhead, int dEVLnumber)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    tList* dEVLtemp = dEVLhead;
    tList* dEVLtemp2;
    if (dEVLtemp->value == dEVLnumber && dEVLtemp->next == NULL)
        delete dEVLtemp;
    else if (dEVLtemp->value == dEVLnumber && dEVLtemp->next != NULL)
    {
        dEVLtemp2 = dEVLtemp->next;
        dEVLtemp->next = NULL;
        dEVLtemp2->prev = NULL;
        delete dEVLtemp;
    }
    else if (dEVLtemp->value != dEVLnumber)
    {
        while (dEVLtemp->value != dEVLnumber && dEVLtemp->next != NULL)
            dEVLtemp = dEVLtemp->next;
        if (dEVLtemp->value == dEVLnumber && dEVLtemp->next == NULL)
        {
            dEVLtemp2 = dEVLtemp->prev;
            dEVLtemp2->next = NULL;
            dEVLtemp->prev = NULL;
            delete dEVLtemp;
        }
        else if (dEVLtemp->value == dEVLnumber && dEVLtemp->next != NULL)
        {
            dEVLtemp2 = dEVLtemp->prev;
            dEVLtemp2->next = dEVLtemp->next;
            dEVLtemp2 = dEVLtemp2->next;
            dEVLtemp2->prev = dEVLtemp->prev;
            dEVLtemp->prev = NULL;
            dEVLtemp->next = NULL;
            delete dEVLtemp;
        }
        else if (dEVLtemp->value != dEVLnumber)
        {
            cout << "Element not found. Error!\n";
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "Time: ";
            cout << result.count();
            cout << " ns\n\n";
            return;
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << '\n';
    cout << "Element delete successfully.\n";
    printList(dEVLhead);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
}

void deleteElemIndexListTime(tList* dEILhead, int dEILposition)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    tList* DEILtemp = dEILhead;
    if (dEILposition == 0)
    {
        dEILhead = dEILhead->next;
        DEILtemp->next = NULL;
        dEILhead->prev = NULL;
        delete DEILtemp;
    }
    else
    {
        tList* DEILtemp2 = DEILtemp->next;
        int i = 1;
        for (i; i != dEILposition && DEILtemp->next != NULL; i++)
            DEILtemp = DEILtemp->next;
        if (i == dEILposition && DEILtemp->next == NULL)
        {
            DEILtemp2 = DEILtemp;
            DEILtemp = DEILtemp->prev;
            DEILtemp2->prev = NULL;
            DEILtemp->next = NULL;
            delete DEILtemp2;
        }
        else if (i == dEILposition && DEILtemp->next != NULL)
        {
            DEILtemp2 = DEILtemp;
            DEILtemp = DEILtemp->prev;
            DEILtemp->next = DEILtemp2->next;
            DEILtemp2->next = NULL;
            DEILtemp = DEILtemp->next;
            DEILtemp->prev = DEILtemp2->prev;
            DEILtemp2->prev = NULL;
            delete DEILtemp2;
        }
        else
        {
            cout << "Element not found. Error!\n";
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "Time: ";
            cout << result.count();
            cout << " ns\n\n";
            return;
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << '\n';
    cout << "Element delete successfully.\n";
    printList(dEILhead);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
}

void IDZ()
{
    tList* IDZList = new tList;
    tList* IDZpos = NULL;
    tList* cTLtemp = IDZList;
    cTLtemp->value = (rand() % 101) - 50;
    for (int i = 1; i < 10; i++)
    {
        tList* elem = new tList;
        elem->value = (rand() % 101) - 50;
        elem->prev = cTLtemp;
        cTLtemp->next = elem;
        cTLtemp = cTLtemp->next;
    }
    printList(IDZList);
    cout << "\nEnter elements of array\n";
    int* IDZArray2 = new int[100];
    int countEl = 1;
    cin >> IDZArray2[0];
    for (int i = 1; cin.get() != '\n'; i++)
    {
        cin >> IDZArray2[i];
        countEl++;
    }
    int* IDZArray3 = new int[countEl];
    for (int i = 0; i < countEl; i++)
        IDZArray3[i] = IDZArray2[i];
    delete[] IDZArray2;
    printArray(IDZArray3, countEl);
    IDZpos = IDZList;
    do
    {
        IDZpos->value += rand() % 6;
        IDZpos = IDZpos->next;
    } while (IDZpos);
    printList(IDZList);
    int* IDZArray = new int[countEl], posEl = 0;
    for (int i = 0; i < countEl; i++)
    {
        if (IDZArray3[i] < 0)
        {
            IDZArray[posEl] = IDZArray3[i];
            posEl++;
        }
    }
    cout << "\nNew array:\n";
    printArray(IDZArray, posEl);
    IDZList = deleteList(IDZList);
    delete IDZList;
    delete[]IDZArray;
    delete[]IDZArray3;
    system("Pause");
}

void menu(tList* mhead)
{
    int* arr = NULL;
    system("cls");
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start2, end2;
    nanoseconds result2;
    int punktMenu;
    cout << "Which action with you want to do? Choose the number\n"
        << "1 - Enter count of elements and create new list\n"
        << "2 - Enter sequence of elements and create new list\n"
        << "3 - Check speed of creation lists\n"
        << "4 - Add element in list\n"
        << "5 - Delete element by value from list\n"
        << "6 - Delete element by index from list\n"
        << "7 - Exchange elements in list\n"
        << "8 - Get element by value from list\n"
        << "9 - Get element by index from list\n"
        << "10 - Check speed add, delete, and get\n"
        << "11 - Work with massive\n"
        << "12 - IDZ\n"
        << "0 - Exit\n\n";
    cin >> punktMenu;
    system("cls");
    switch (punktMenu)
    {
    case 1:
        system("cls");
        if (mhead->next != NULL)
            mhead = deleteList(mhead);
        int countElements;
        while (true)
        {
            cout << "Enter count of elements in list:\n";
            cin >> countElements;
            if (countElements > 0)
            {
                createTList(mhead, countElements);
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menu(mhead);
        break;
    case 2:
        system("cls");
        if (mhead->next != NULL)
            mhead = deleteList(mhead);
        createTList2(mhead);
        menu(mhead);
        break;
    case 3:
        createTListTime(CountElementsCheckTimeList);
        createTListTime2();
        system("Pause");
        menu(mhead);
        break;
    case 4:
        system("cls");
        int newElemValue, newElemPosition;
        while (true)
        {
            cout << "Enter value and position of new element in list:\n";
            cin >> newElemValue >> newElemPosition;
            if (newElemPosition > 0)
            {
                addList(mhead, newElemValue, newElemPosition - 1);
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menu(mhead);
        break;
    case 5:
        system("cls");
        if (mhead->next == NULL)
        {
            cout << "Error. List not created\n";
            system("Pause");
            menu(mhead);
            break;
        }
        int delElemValue;
        cout << "Enter value of element in list:\n";
        cin >> delElemValue;
        deleteElemValueList(mhead, delElemValue);
        menu(mhead);
        break;
    case 6:
        system("cls");
        if (mhead->next == NULL)
        {
            cout << "Error. List not created\n";
            system("Pause");
            menu(mhead);
            break;
        }
        int delElemIndex;
        while (true)
        {
            cout << "Enter index of element in list:\n";
            cin >> delElemIndex;
            if (delElemIndex >= 0)
            {
                deleteElemIndexList(mhead, delElemIndex);
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menu(mhead);
        break;
    case 7:
        system("cls");
        if (mhead->next == NULL)
        {
            cout << "Error. List not created\n";
            system("Pause");
            menu(mhead);
            break;
        }
        int swapPos1, swapPos2;
        while (true)
        {
            cout << "Enter position elements in list to swap them:\n";
            cin >> swapPos1 >> swapPos2;
            if (swapPos1 > 0 && swapPos2 > 0)
            {
                swapElemList(mhead, swapPos1 - 1, swapPos2 - 1);
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menu(mhead);
        break;
    case 8:
        system("cls");
        if (mhead->next == NULL)
        {
            cout << "Error. List not created\n";
            system("Pause");
            menu(mhead);
            break;
        }
        int getElemValue;
        cout << "Enter value of element to get from list:\n";
        cin >> getElemValue;
        getElemValueList(mhead, getElemValue);
        system("Pause");
        menu(mhead);
        break;
    case 9:
        system("cls");
        if (mhead->next == NULL)
        {
            cout << "Error. List not created\n";
            system("Pause");
            menu(mhead);
            break;
        }
        int getPos;
        while (true)
        {
            cout << "Enter position element in list to get them:\n";
            cin >> getPos;
            if (getPos > 0)
            {
                getElemIndexList(mhead, getPos);
                system("Pause");
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menu(mhead);
        break;
    case 10:
        system("cls");
        if (mhead->next == NULL)
        {
            cout << "Error. List not created\n";
            system("Pause");
            menu(mhead);
            break;
        }
        addListTime(mhead, 7, 2);
        deleteElemValueListTime(mhead, 7);
        deleteElemIndexListTime(mhead, 2);
        start2 = steady_clock::now();
        getElemValueList(mhead, 5);
        end2 = steady_clock::now();
        result2 = duration_cast<nanoseconds>(end2 - start2);
        cout << "Time: ";
        cout << result2.count();
        cout << " ns\n\n";
        start2 = steady_clock::now();
        getElemIndexList(mhead, 2);
        end2 = steady_clock::now();
        result2 = duration_cast<nanoseconds>(end2 - start2);
        cout << "Time: ";
        cout << result2.count();
        cout << " ns\n\n";
        system("Pause");
        menu(mhead);
        break;
    case 11:
        menuArray(arr);
        menu(mhead);
        break;
    case 12:
        IDZ();
        menu(mhead);
        break;
    case 0:
        break;
    default:
        cout << "Error! Repeat, please.\n\n";
        system("Pause");
        menu(mhead);
        break;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    tList* head = new tList;
    menu(head);
    head = deleteList(head);
    delete head;
    return 0;
}