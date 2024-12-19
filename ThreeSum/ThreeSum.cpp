// ThreeSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int CountElement(const std::vector<int>& vec, int toBeCounted)
{
    int count = 0;
    for (auto i : vec)
    {
        if (i == toBeCounted)
            ++count;
    }

    return count;
}

bool Equal(const std::vector<int>& v1, const std::vector<int>& v2)
{
    if (v1.size() != v2.size())
        return false;

    for (auto i : v1)
    {
        if (CountElement(v1, i) != CountElement(v2, i))
            return false;
    }

    return true;
}

bool ArrayExisted(const std::vector<std::vector<int>>& vov, const std::vector<int>& v)
{
    for (auto& vv : vov)
    {
        if (Equal(vv, v))
            return true;
    }

    return false;
}

void ThreeSum(const std::vector<int>& vec, int start, int sum, std::vector<int>& a, std::vector<std::vector<int>>& result)
{
    if (sum == 0 && a.size() == 3)
    {
        if (!ArrayExisted(result, a))
            result.push_back(a);
        return;
    }

    if (start == static_cast<int>(vec.size()) || a.size() == 3)
        return;

    for (size_t i = start; i < vec.size(); ++i)
    {
        a.push_back(vec[i]);
        ThreeSum(vec, static_cast<int>(i + 1), sum - vec[i], a, result);
        a.pop_back();
    }
}

std::vector<std::vector<int>> ThreeSum(std::vector<int>& vec)
{
    std::vector<std::vector<int>> result;
    //std::vector<int> a;
    //ThreeSum(vec, 0, 0, a, result);

    for (auto i = vec.cbegin(); i != vec.cend()-2; ++i)
    {
        for (auto j = i + 1; j != vec.cend()-1; ++j)
        {
            for (auto k = j + 1; k != vec.cend(); ++k)
            {
                if (*i + *j + *k == 0)
                {
                    std::vector<int> temp{ *i, *j, *k };

                    if (!ArrayExisted(result, temp))
                        result.push_back(std::move(temp));
                }
            }
        }
    }

    return result;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of elements in the array: ";
        std::cin >> count;
        if (count < 3)
            break;

        std::vector<int> vec(count);
        std::cout << "The number array: ";
        for (int i = 0; i < count; ++i)
            std::cin >> vec[i];

        std::vector<std::vector<int>> arraiesFound = ThreeSum(vec);
        for (auto& arr : arraiesFound)
        {
            for (auto i : arr)
            {
                std::cout << i << ", ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
