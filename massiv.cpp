#include <iostream>
#include <chrono>
#define CountElementsCheckTimeArray 10

using namespace std;
using namespace chrono;

int countElementsMassiv = 0;

void printArray(int* parray, int psize)
{
    for (int i = 0; i < psize; i++)
        cout << parray[i] << ' ';
    cout << '\n';
}

int* createArray(int csize)
{
    int* carray = new int[csize];
    for (int i = 0; i < csize; i++)
        carray[i] = rand() % 100;
    countElementsMassiv = csize;
    cout << "Array created successfully.\n";
    printArray(carray, csize);
    system("Pause");
    return carray;
}

int* createArray2()
{
    cout << "Enter elements of array\n";
    int* carray2 = new int[100];
    int countEl = 1;
    cin >> carray2[0];
    for (int i = 1; cin.get() != '\n'; i++)
    {
        cin >> carray2[i];
        countEl++;
    }
    int* carray3 = new int[countEl];
    for (int i = 0; i < countEl; i++)
        carray3[i] = carray2[i];
    delete[] carray2;
    countElementsMassiv = countEl;
    cout << "Array created successfully.\n";
    printArray(carray3, countEl);
    system("Pause");
    return carray3;
}

void createArrayTime(int cTsize)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    int* cTarray = new int[cTsize];
    for (int i = 0; i < cTsize; i++)
        cTarray[i] = rand() % 100;
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << '\n';
    cout << "Array created successfully.\n";
    printArray(cTarray, cTsize);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
    delete[]cTarray;
}

void createArrayTime2()
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    cout << "Enter elements of array\n";
    int* cTarray2 = new int[100];
    int countEl = 1;
    cin >> cTarray2[0];
    start = steady_clock::now();
    for (int i = 1; cin.get() != '\n'; i++)
    {
        cin >> cTarray2[i];
        countEl++;
    }
    int* cTarray3 = new int[countEl];
    for (int i = 0; i < countEl; i++)
        cTarray3[i] = cTarray2[i];
    delete[] cTarray2;
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << '\n';
    printArray(cTarray3, countEl);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
    delete[] cTarray3;
    system("Pause");
}

int* addArray(int* aarray, int avalue, int apos)
{
    int* tempArray = new int[countElementsMassiv + 1];
    for (int i = 0; i < apos; i++)
        tempArray[i] = aarray[i];
    tempArray[apos] = avalue;
    countElementsMassiv++;
    for (int i = apos + 1; i < countElementsMassiv; i++)
        tempArray[i] = aarray[i - 1];
    delete[]aarray;
    cout << "Element add successfully.\n";
    printArray(tempArray, countElementsMassiv);
    system("Pause");
    return tempArray;
}

int* deleteElemValueArray(int* dEVarray, int dEVAnumber)
{
    int i = 0;
    int* temp = new int[countElementsMassiv - 1];
    for (i; i < countElementsMassiv && dEVarray[i] != dEVAnumber; i++);
    if (dEVarray[i] == dEVAnumber)
    {
        for (int j = 0; j < i; j++)
            temp[j] = dEVarray[j];
        for (int j = i; j < countElementsMassiv - 1; j++)
            temp[j] = dEVarray[j + 1];
        delete[]dEVarray;
    }
    else
    {
        cout << "Element not found. Error!\n";
        return dEVarray;
    }
    cout << "Element delete successfully.\n";
    countElementsMassiv--;
    printArray(temp, countElementsMassiv);
    system("Pause");
    return temp;
}

int* deleteElemIndexArray(int* dEIarray, int dEIposition)
{
    int* temp = new int[countElementsMassiv - 1];
    for (int j = 0; j < dEIposition; j++)
        temp[j] = dEIarray[j];
    for (int j = dEIposition; j < countElementsMassiv - 1; j++)
        temp[j] = dEIarray[j + 1];
    delete[]dEIarray;
    cout << "Element delete successfully.\n";
    countElementsMassiv--;
    printArray(temp, countElementsMassiv);
    system("Pause");
    return temp;
}

int* swapElemArray(int* sEarray, int sEAelem1, int sEAelem2)
{
    if (sEAelem1 == sEAelem2)
    {
        cout << "Same index. Error!\n";
        system("Pause");
        return sEarray;
    }
    swap(sEarray[sEAelem1], sEarray[sEAelem2]);
    cout << "Element swap successfully.\n";
    printArray(sEarray, countElementsMassiv);
    system("Pause");
    return sEarray;
}

int* getElemValueArray(int* gEVarray, int gEVAnumber)
{
    int i = 0;
    for (i; i < countElementsMassiv && gEVarray[i] != gEVAnumber; i++);
    if (gEVarray[i] == gEVAnumber)
        cout << "Element was found. Position " << i << '\n';
    else
        cout << "Element not found.\n";
    return gEVarray;
}

int* getElemIndexArray(int* gEIarray, int gEIAposition)
{
    cout << "Element was found. Position " << gEIAposition << ". Value: " << gEIarray[gEIAposition] << ".\n";
    return gEIarray;
}

int* addArrayTime(int* aTarray, int aATvalue, int aATpos)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    int* tempArray = new int[countElementsMassiv + 1];
    for (int i = 0; i < aATpos; i++)
        tempArray[i] = aTarray[i];
    tempArray[aATpos] = aATvalue;
    countElementsMassiv++;
    for (int i = aATpos + 1; i < countElementsMassiv; i++)
        tempArray[i] = aTarray[i - 1];
    delete[]aTarray;
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Element add successfully.\n";
    printArray(tempArray, countElementsMassiv);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
    system("Pause");
    return tempArray;
}

int* deleteElemValueArrayTime(int* dEVarrayT, int dEVATnumber)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    int i = 0;
    int* temp = new int[countElementsMassiv - 1];
    for (i; i < countElementsMassiv && dEVarrayT[i] != dEVATnumber; i++);
    if (dEVarrayT[i] == dEVATnumber)
    {
        for (int j = 0; j < i; j++)
            temp[j] = dEVarrayT[j];
        for (int j = i; j < countElementsMassiv - 1; j++)
            temp[j] = dEVarrayT[j + 1];
        delete[]dEVarrayT;
    }
    else
    {
        cout << "Element not found. Error!\n";
        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);
        cout << "Time: ";
        cout << result.count();
        cout << " ns\n\n";
        return dEVarrayT;
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Element delete successfully.\n";
    countElementsMassiv--;
    printArray(temp, countElementsMassiv);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
    system("Pause");
    return temp;
}

int* deleteElemIndexArrayTime(int* dEIarrayT, int dEIATposition)
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    int* temp = new int[countElementsMassiv - 1];
    for (int j = 0; j < dEIATposition; j++)
        temp[j] = dEIarrayT[j];
    for (int j = dEIATposition; j < countElementsMassiv - 1; j++)
        temp[j] = dEIarrayT[j + 1];
    delete[]dEIarrayT;
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Element delete successfully.\n";
    countElementsMassiv--;
    printArray(temp, countElementsMassiv);
    cout << "Time: ";
    cout << result.count();
    cout << " ns\n\n";
    system("Pause");
    return temp;
}

void menuArray(int* marray)
{
    system("cls");
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start2, end2;
    nanoseconds result2;
    int punktMenuArray;
    cout << "Which action with you want to do? Choose the number\n"
        << "1 - Enter count of elements and create new array\n"
        << "2 - Enter sequence of elements and create new array\n"
        << "3 - Check speed of creation arrays\n"
        << "4 - Add element in array\n"
        << "5 - Delete element by value from array\n"
        << "6 - Delete element by index from array\n"
        << "7 - Exchange elements in array\n"
        << "8 - Get element by value from array\n"
        << "9 - Get element by index from array\n"
        << "10 - Check speed add, delete, and get\n"
        << "0 - Exit\n\n";
    cin >> punktMenuArray;
    system("cls");
    switch (punktMenuArray)
    {
    case 1:
        system("cls");
        if (countElementsMassiv > 0)
        {
            delete[]marray;
            countElementsMassiv = 0;
        }
        int countElementsArray;
        while (true)
        {
            cout << "Enter count of elements in array:\n";
            cin >> countElementsArray;
            if (countElementsArray > 0)
            {
                marray = createArray(countElementsArray);
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menuArray(marray);
        break;
    case 2:
        system("cls");
        if (countElementsMassiv > 0)
        {
            delete[]marray;
            countElementsMassiv = 0;
        }
        marray = createArray2();
        menuArray(marray);
        break;
    case 3:
        createArrayTime(CountElementsCheckTimeArray);
        createArrayTime2();
        menuArray(marray);
        break;
    case 4:
        system("cls");
        int newElemValueMassiv, newElemPositionMassiv;
        while (true)
        {
            cout << "Enter value and position of new element in array:\n";
            cin >> newElemValueMassiv >> newElemPositionMassiv;
            if (newElemPositionMassiv > 0 && newElemPositionMassiv <= countElementsMassiv)
            {
                marray = addArray(marray, newElemValueMassiv, newElemPositionMassiv);
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menuArray(marray);
        break;
    case 5:
        system("cls");
        if (countElementsMassiv == NULL)
        {
            cout << "Error. Massiv not created\n";
            system("Pause");
            menuArray(marray);
            break;
        }
        int delElemValueMassiv;
        cout << "Enter value of element in array:\n";
        cin >> delElemValueMassiv;
        marray = deleteElemValueArray(marray, delElemValueMassiv);
        menuArray(marray);
        break;
    case 6:
        system("cls");
        if (countElementsMassiv == NULL)
        {
            cout << "Error. Massiv not created\n";
            system("Pause");
            menuArray(marray);
            break;
        }
        int delElemIndexMassiv;
        while (true)
        {
            cout << "Enter index of element in array:\n";
            cin >> delElemIndexMassiv;
            if (delElemIndexMassiv > 0 && delElemIndexMassiv < countElementsMassiv)
            {
                marray = deleteElemIndexArray(marray, delElemIndexMassiv);
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menuArray(marray);
        break;
    case 7:
        system("cls");
        if (countElementsMassiv == NULL)
        {
            cout << "Error. Massiv not created\n";
            system("Pause");
            menuArray(marray);
            break;
        }
        int swapPosMassiv1, swapPosMassiv2;
        while (true)
        {
            cout << "Enter position elements in array to swap them:\n";
            cin >> swapPosMassiv1 >> swapPosMassiv2;
            if (swapPosMassiv1 > 0 && swapPosMassiv2 > 0 && swapPosMassiv1 < countElementsMassiv && swapPosMassiv2 < countElementsMassiv)
            {
                marray = swapElemArray(marray, swapPosMassiv1, swapPosMassiv2);
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menuArray(marray);
        break;
    case 8:
        system("cls");
        if (countElementsMassiv == NULL)
        {
            cout << "Error. Massiv not created\n";
            system("Pause");
            menuArray(marray);
            break;
        }
        int getElemValueMassiv;
        cout << "Enter value of element to get from massiv:\n";
        cin >> getElemValueMassiv;
        marray = getElemValueArray(marray, getElemValueMassiv);
        system("Pause");
        menuArray(marray);
        break;
    case 9:
        system("cls");
        if (countElementsMassiv == NULL)
        {
            cout << "Error. Massiv not created\n";
            system("Pause");
            menuArray(marray);
            break;
        }
        int getPosMassiv;
        while (true)
        {
            cout << "Enter position element in array to get them:\n";
            cin >> getPosMassiv;
            if (getPosMassiv > 0 && getPosMassiv < countElementsMassiv)
            {
                marray = getElemIndexArray(marray, getPosMassiv);
                system("Pause");
                break;
            }
            else if (getPosMassiv > 0 && getPosMassiv >= countElementsMassiv)
            {
                cout << "Element not found.\n";
                system("Pause");
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menuArray(marray);
        break;
    case 10:
        system("cls");
        if (countElementsMassiv == NULL)
        {
            cout << "Error. Massiv not created\n";
            system("Pause");
            menuArray(marray);
            break;
        }
        marray = addArrayTime(marray, 7, 2);
        marray = deleteElemValueArrayTime(marray, 7);
        marray = deleteElemIndexArrayTime(marray, 2);
        start2 = steady_clock::now();
        marray = getElemValueArray(marray, 5);
        end2 = steady_clock::now();
        result2 = duration_cast<nanoseconds>(end2 - start2);
        cout << "Time: ";
        cout << result2.count();
        cout << " ns\n\n";
        start2 = steady_clock::now();
        marray = getElemIndexArray(marray, 2);
        end2 = steady_clock::now();
        result2 = duration_cast<nanoseconds>(end2 - start2);
        cout << "Time: ";
        cout << result2.count();
        cout << " ns\n\n";
        system("Pause");
        menuArray(marray);
        break;
    case 0:
        delete[]marray;
        countElementsMassiv = 0;
        break;
    default:
        cout << "Error! Repeat, please.\n\n";
        system("Pause");
        menuArray(marray);
        break;
    }
}