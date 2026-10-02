#include <iostream>
#include <vector>

// 1. Создание и динамическое заполнение
void createAndFillVector(int N)
{
    std::vector<int> vec(N);

    for (int i = 0; i < N; i++)
    {
        vec[i] = i + 1;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n";
    std::cout << "size: " << vec.size() << "\n";
    std::cout << "capacity: " << vec.capacity() << "\n";
}


// 2. Управление вместимостью пустого вектора
void workWithEmptyVector()
{
    std::vector<int> vec;

    for (int i = 1; i <= 10; i++)
    {
        vec.push_back(i);

        std::cout << "size: " << vec.size()
                  << ", capacity: " << vec.capacity() << "\n";
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n";
}


// 3. Создание и динамическое заполнение
std::vector<int> createVectorFromInput()
{
    std::vector<int> vec;
    int x;

    std::cin >> x;

    while (x != 0)
    {
        vec.push_back(x);
        std::cin >> x;
    }

    return vec;
}


// 4. Удаление элементов с конца
int removeElementsGreaterThan(
    std::vector<int>& vec,
    int threshold)
{
    int count = 0;

    while (!vec.empty() && vec.back() > threshold)
    {
        vec.pop_back();
        count++;
    }

    return count;
}


// 5. Управление вместимостью
void manageCapacity(std::vector<int>& vec)
{
    std::cout << "size: " << vec.size() << "\n";
    std::cout << "capacity: " << vec.capacity() << "\n";

    vec.reserve(vec.size() + 500);

    for (int i = 1; i <= 500; i++)
    {
        vec.push_back(i);
    }

    std::cout << "size: " << vec.size() << "\n";
    std::cout << "capacity: " << vec.capacity() << "\n";
}


// 6. Изменение размера вектора
template <typename T>
void resizeVector(
    std::vector<T>& vec,
    int newSize,
    T value)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n";

    vec.resize(newSize, value);

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n";
}


// 7. Слияние отсортированных векторов
std::vector<int> mergeSortedVectors(
    const std::vector<int>& vec1,
    const std::vector<int>& vec2)
{
    std::vector<int> merged;

    int i = 0;
    int j = 0;

    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i] <= vec2[j])
        {
            merged.push_back(vec1[i]);
            i++;
        }
        else
        {
            merged.push_back(vec2[j]);
            j++;
        }
    }

    while (i < vec1.size())
    {
        merged.push_back(vec1[i]);
        i++;
    }

    while (j < vec2.size())
    {
        merged.push_back(vec2[j]);
        j++;
    }

    return merged;
}


// 8. Поиск подпоследовательности
int findSubsequence(
    const std::vector<int>& main_vec,
    const std::vector<int>& sub_vec)
{
    if (sub_vec.size() == 0)
    {
        return 0;
    }

    if (sub_vec.size() > main_vec.size())
    {
        return -1;
    }

    for (int i = 0;
         i <= main_vec.size() - sub_vec.size();
         i++)
    {
        bool found = true;

        for (int j = 0; j < sub_vec.size(); j++)
        {
            if (main_vec[i + j] != sub_vec[j])
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            return i;
        }
    }

    return -1;
}


// 9. Группировка смежных элементов
std::vector<std::vector<int>> groupAdjacent(
    const std::vector<int>& vec)
{
    std::vector<std::vector<int>> groups;

    if (vec.empty())
    {
        return groups;
    }

    std::vector<int> group;
    group.push_back(vec[0]);

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == vec[i - 1])
        {
            group.push_back(vec[i]);
        }
        else
        {
            groups.push_back(group);

            group.clear();
            group.push_back(vec[i]);
        }
    }

    groups.push_back(group);

    return groups;
}


// 10. Фильтрация с сохранением порядка
template <typename T, typename Predicate>
std::vector<T> filterVector(
    const std::vector<T>& vec,
    Predicate predicate)
{
    std::vector<T> filtered;

    for (int i = 0; i < vec.size(); i++)
    {
        if (predicate(vec[i]))
        {
            filtered.push_back(vec[i]);
        }
    }

    return filtered;
}


bool isEven(int x)
{
    return x % 2 == 0;
}


int main()
{
    // 1
    createAndFillVector(5);


    // 2
    workWithEmptyVector();


    // 3
    std::vector<int> inputVec = createVectorFromInput();

    std::cout << "size: " << inputVec.size() << "\n";

    for (int i = 0; i < inputVec.size(); i++)
    {
        std::cout << inputVec[i] << " ";
    }

    std::cout << "\n";


    // 4
    std::vector<int> v = {1, 3, 5, 7, 9};

    int removed = removeElementsGreaterThan(v, 5);

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

    std::cout << "\n";
    std::cout << "removed: " << removed << "\n";


    // 5
    std::vector<int> capacityVec;

    manageCapacity(capacityVec);


    // 6
    std::vector<int> resizeVec = {1, 2, 3};

    resizeVector(resizeVec, 5, 42);


    // 7
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8, 9};

    std::vector<int> merged =
        mergeSortedVectors(vec1, vec2);

    for (int i = 0; i < merged.size(); i++)
    {
        std::cout << merged[i] << " ";
    }

    std::cout << "\n";


    // 8
    std::vector<int> main_vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> sub_vec = {3, 4, 5};

    int index = findSubsequence(main_vec, sub_vec);

    std::cout << index << "\n";


    // 9
    std::vector<int> groupVec =
        {1, 1, 2, 2, 2, 3, 1, 1};

    std::vector<std::vector<int>> groups =
        groupAdjacent(groupVec);

    for (int i = 0; i < groups.size(); i++)
    {
        for (int j = 0; j < groups[i].size(); j++)
        {
            std::cout << groups[i][j] << " ";
        }

        std::cout << "\n";
    }


    // 10
    std::vector<int> filterVec =
        {1, 2, 3, 4, 5, 6};

    std::vector<int> filtered =
        filterVector(filterVec, isEven);

    for (int i = 0; i < filtered.size(); i++)
    {
        std::cout << filtered[i] << " ";
    }

    std::cout << "\n";

    return 0;
}
