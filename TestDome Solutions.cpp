#include <stdexcept>
#include <iostream>
#include <set>
class Song
{
public:
    Song(std::string name) : name(name), nextSong(NULL) {}

    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isInRepeatingPlaylist()
    {
        Song* visitNode = this;
        std::set<Song*> list;
        for (; visitNode != NULL; visitNode = visitNode->nextSong)
        {
            auto ret = list.insert(visitNode);
            if (ret.second == false)
            {
                return true;
            }
        }
        return false;
        throw std::logic_error("Waiting to be implemented");
    }

private:
    const std::string name;
    Song* nextSong;
};

int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");

    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isInRepeatingPlaylist();
}



#include <iostream>
#include <vector>

std::vector<int> simulate(const std::vector<int>& entries)
{
    std::vector<int> vec;
    if (entries.empty())
    {
        return vec;
    }
    else
    {
        for (int i = 0; i < entries.size(); i++)
        {
            int left = i - 3;
            int right = i + 4;
            vec.push_back(entries[i]);
            if (left<0 && right >(entries.size() - 1))
            {
                continue;
            }
            else if (left < 0 && right <= (entries.size() - 1))
            {
                if (entries[right] >= entries[i])
                {
                    vec[i] = 0;
                }
            }
            else if (left >= 0 && right > (entries.size() - 1))
            {
                if (entries[left] >= entries[i])
                {
                    vec[i] = 0;
                }
            }
            else if (left >= 0 && right <= (entries.size() - 1))
            {
                if (entries[left] >= entries[i] || entries[right] >= entries[i])
                {
                    vec[i] = 0;
                }
            }
        }
    }
    return vec;
}

#ifndef RunTests
int main()
{
    std::vector<int> result = simulate({ 1, 2, 0, 5, 0, 2, 4, 3, 3, 3 });
    for (int value : result)
    {
        std::cout << value << " ";
    }
    // Expected output
    // 1, 0, 0, 5, 0, 0, 0, 3, 3, 0
}
#endif

#include <iostream>
#include <string>

class MultipleChoiceTest
{
public:
    MultipleChoiceTest(int questionsCount)
    {
        this->questionsCount = questionsCount;
        answers = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            answers[i] = -1;
        }
    }

    void setAnswer(int questionIndex, int answer)
    {
        answers[questionIndex] = answer;
    }

    int getAnswer(int questionIndex) const
    {
        return answers[questionIndex];
    }

protected:
    int questionsCount;

private:
    int* answers;
};

class TimedMultipleChoiceTest : public MultipleChoiceTest
{
public:
    TimedMultipleChoiceTest(int questionsCount)
        : MultipleChoiceTest(questionsCount)
    {
        times = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            times[i] = 0;
        }
    }

    void setTime(int questionIndex, int time)
    {
        times[questionIndex] = time;
    }

    int getTime(int questionIndex) const
    {
        return times[questionIndex];
    }

private:
    int* times;
};

#ifndef RunTests
void executeTest()
{
    MultipleChoiceTest test(5);
    for (int i = 0; i < 5; i++)
    {
        test.setAnswer(i, i);
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Test: " << i + 1 << "\n";
        executeTest();
    }
}
#endif

#include <iostream>
#include <vector>
#include <set>
std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
    std::set<std::string> list;
    std::vector<std::string> listName;
    for (auto cur : names1)
    {
        list.insert(cur);
    }
    for (auto cur : names2)
    {
        list.insert(cur);
    }
    for (auto str : list)
    {
        listName.push_back(str);
    }
    return listName;
}

#ifndef RunTests
int main()
{
    std::vector<std::string> names1 = { "Ava", "Emma", "Olivia" };
    std::vector<std::string> names2 = { "Olivia", "Sophia", "Emma" };

    std::vector<std::string> result = unique_names(names1, names2);
    for (auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}
#endif
#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>
std::pair<double, double> findRoots(double a, double b, double c)
{
    double delta = pow(b, 2) - 4 * a * c;
    if (delta < 0) return std::pair<double, double>();
    else if (delta == 0) return std::pair<double, double>((-1) * b / 2 * a, (-1) * b / 2 * a);
    else return std::pair<double, double>(((-1) * b + sqrt(delta)) / (2 * a), ((-1) * b - sqrt(delta)) / (2 * a));
}

#ifndef RunTests
int main()
{
    std::pair<double, double> roots = findRoots(2, 10, 8);
    std::cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second);
}
#endif

#include <vector>
#include <stdexcept>
#include <iostream>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    if (lessThan < sortedVector.front()) return 0;
    if (lessThan > sortedVector.back()) return sortedVector.size();
    if (lessThan == sortedVector.back()) return sortedVector.size() - 1;
    int left = 0;
    int right = sortedVector.size() - 1;
    while (right >= left)
    {
        int mid = (left + right) / 2;
        if (sortedVector[mid] < lessThan) left = mid + 1;
        else if (sortedVector[mid] > lessThan) right = mid - 1;
        else return mid;
    }
    return right + 1;
}

#ifndef RunTests
int main()
{
    std::vector<int> v{ 1, 3, 5, 7 };
    std::cout << countNumbers(v, 4);
}
#endif

#include <iostream>
#include <string>

class MultipleChoiceTest
{
public:
    MultipleChoiceTest(int questionsCount)
    {
        this->questionsCount = questionsCount;
        answers = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            answers[i] = -1;
        }
    }

    void setAnswer(int questionIndex, int answer)
    {
        answers[questionIndex] = answer;
    }

    int getAnswer(int questionIndex) const
    {
        return answers[questionIndex];
    }

    virtual ~MultipleChoiceTest()
    {
        delete[] answers;
    }
protected:
    int questionsCount;

private:
    int* answers;
};

class TimedMultipleChoiceTest : public MultipleChoiceTest
{
public:
    TimedMultipleChoiceTest(int questionsCount)
        : MultipleChoiceTest(questionsCount)
    {
        times = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            times[i] = 0;
        }
    }

    void setTime(int questionIndex, int time)
    {
        times[questionIndex] = time;
    }

    int getTime(int questionIndex) const
    {
        return times[questionIndex];
    }

    virtual ~TimedMultipleChoiceTest()
    {
        delete[] times;
    }
private:
    int* times;
};

#ifndef RunTests
void executeTest()
{
    MultipleChoiceTest test(5);
    for (int i = 0; i < 5; i++)
    {
        test.setAnswer(i, i);
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Test: " << i + 1 << "\n";
        executeTest();
    }
}
#endif

unordered_map 和 map区别
#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
	std::unordered_map<int, int> view;
	for (int i = 0; i < list.size(); ++i)
	{
		auto iter = view.find(sum - list[i]);
		if ( iter !=view.end()) return std::pair<int, int>(i,iter->second);
		view[list[i]] = i;
	}
	return std::pair<int, int>(-1, -1);
}

#ifndef RunTests
int main()
{
	std::vector<int> list = { 3, 1, 5, 7, 5, 9 };
	std::pair<int, int> indices = findTwoSum(list, 10);
	std::cout << indices.first << '\n' << indices.second;
}
#endif

#include <iostream>
#include <string>

class TextInput
{
public:
    virtual void add(char c) { str.push_back(c); }
    virtual ~TextInput() {  };
    std::string getValue() { return str; }
private:
    std::string str;
};

class NumericInput : public TextInput { 
public :
    void add(char c) {
        if (c >= '0' && c <= '9')
        {        
            TextInput::add(c);
        }
    }
};

#ifndef RunTests
int main()
{
    TextInput* input = new TextInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif

#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node* getLeft() const
    {
        return left;
    }

    Node* getRight() const
    {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value)
    {
        if (root.getValue() == value) return true;
        Node* visitNode = new Node(root.getValue(),root.getLeft(),root.getRight());
        while (visitNode)
        {
            if (visitNode->getValue() < value)
            {
                //走右边
                visitNode = visitNode->getRight();
            }
            else if (visitNode->getValue() > value)
            {
                //走左边
                visitNode = visitNode->getLeft();
            }
            else if (visitNode->getValue() == value)
            {
                return true;
            }
        }
        return false;
    }
};

#ifndef RunTests
int main()
{
    Node n1(1, NULL, NULL);
    Node n3(3, NULL, NULL);
    Node n2(2, &n1, &n3);

    std::cout << BinarySearchTree::contains(n2, 3);
}
#endif

#include <iostream>
#include <functional>
#include <vector>

template<class T>
std::function<T(T)> makePipeline(const std::vector<std::function<T(T)>>& funcs) {
	return [&funcs](const T& arg) {
		T num = arg;
		for (auto curFunc : funcs)
		{
			num = curFunc(num);
		}
		return num;
	};
}

#ifndef RunTests
int main()
{
	std::vector<std::function<int(int)>> functions;
	functions.push_back([](int x) -> int { return x * 3; });
	functions.push_back([](int x) -> int { return x + 1; });
	functions.push_back([](int x) -> int { return x / 2; });

	std::function<int(int)> func = makePipeline(functions);
	std::cout << func(3); // should print 5
}
#endif

#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
int main()
{
	std::map<std::string, int>myMap{ {"C语言教程",10},{"STL教程",20},{"STL教程2",30} };
	std::map<std::string, int>newMap(myMap.begin(), myMap.end());
	for (auto cur : newMap)
	{
		std::cout << cur.first << " " << cur.second;
	}
	return 0;
}

// Method1  - Route Planner
#include <iostream>
#include <vector>
#include <map>
bool routeSearch(int fromRow, int fromColumn, int toRow, int toColumn, const std::vector<std::vector<bool>>& mapMatrix, std::map<std::pair<int, int>, bool>& visitedMap);
bool routeExists(int fromRow, int fromColumn, int toRow, int toColumn,
    const std::vector<std::vector<bool>>& mapMatrix)
{
	std::map<std::pair<int, int>, bool> visitedMap;
	return routeSearch(fromRow, fromColumn, toRow, toColumn,
		mapMatrix, visitedMap);
}
bool routeSearch(int fromRow, int fromColumn, int toRow, int toColumn, const std::vector<std::vector<bool>>& mapMatrix, std::map<std::pair<int,int>,bool> &visitedMap)
{
	if (fromRow == toRow && fromColumn == toColumn) return true;
	if (fromRow < 0 || fromColumn < 0 || fromRow >= mapMatrix.size() || fromColumn >= mapMatrix[0].size()) return false;
	if (!mapMatrix[fromRow][fromColumn] || !mapMatrix[toRow][toColumn]|| visitedMap[std::make_pair(fromRow, fromColumn)]) return false;
	// 如果当前行列所在值为假，那么便跳过当前移动
	visitedMap[std::make_pair(fromRow, fromColumn)]= true;
	return routeSearch(fromRow - 1, fromColumn, toRow, toColumn, mapMatrix, visitedMap) ||
		routeSearch(fromRow, fromColumn + 1, toRow, toColumn, mapMatrix, visitedMap) ||
		routeSearch(fromRow + 1, fromColumn, toRow, toColumn, mapMatrix, visitedMap) ||
		routeSearch(fromRow, fromColumn - 1, toRow, toColumn, mapMatrix, visitedMap);
}
#ifndef RunTests
int main()
{
    std::vector<std::vector<bool>> mapMatrix{
        {true, false, false},
        {true, true, false},
        {false, true, true}
    };

    std::cout << routeExists(0, 0, 2, 2, mapMatrix) << std::endl;
}
#endif

// Method2
#include <iostream>
#include <vector>
bool routeSearch(int fromRow, int fromColumn, int toRow, int toColumn, const std::vector<std::vector<bool>>& mapMatrix, std::vector<std::vector<bool>>& visitedMap);
bool routeExists(int fromRow, int fromColumn, int toRow, int toColumn,
	const std::vector<std::vector<bool>>& mapMatrix)
{
	std::vector<std::vector<bool>> visitedMap;
	visitedMap.resize(mapMatrix.size());
	for (int i = 0; i < visitedMap.size(); ++i)
	{
		visitedMap[i].resize(mapMatrix[0].size(), false);
	}
	return routeSearch(fromRow, fromColumn, toRow, toColumn,
		mapMatrix, visitedMap);
}
bool routeSearch(int fromRow, int fromColumn, int toRow, int toColumn, const std::vector<std::vector<bool>>& mapMatrix, std::vector<std::vector<bool>>& visitedMap)
{
	if (fromRow == toRow && fromColumn == toColumn) return true;
	if (fromRow < 0 || fromColumn < 0 || fromRow >= mapMatrix.size() || fromColumn >= mapMatrix[0].size()) return false;
	if (!mapMatrix[fromRow][fromColumn] || !mapMatrix[toRow][toColumn] || visitedMap[fromRow][fromColumn]) return false;
	// 如果当前行列所在值为假，那么便跳过当前移动
	visitedMap[fromRow][fromColumn] = true;
	return routeSearch(fromRow - 1, fromColumn, toRow, toColumn, mapMatrix, visitedMap) ||
		routeSearch(fromRow, fromColumn + 1, toRow, toColumn, mapMatrix, visitedMap) ||
		routeSearch(fromRow + 1, fromColumn, toRow, toColumn, mapMatrix, visitedMap) ||
		routeSearch(fromRow, fromColumn - 1, toRow, toColumn, mapMatrix, visitedMap);
}
#ifndef RunTests
int main()
{
	std::vector<std::vector<bool>> mapMatrix{
		{true, false, false},
		{true, true, false},
		{false, true, true}
	};

	std::cout << routeExists(0, 0, 2, 2, mapMatrix) << std::endl;
}
#endif

#include <iostream>
#include <vector>
#include <map>
bool TravelSearch(std::vector<std::vector<bool>>& gameMatrix, int fromRow, int fromColumn, int toRow, int toColumn, std::map<std::pair<int, int>, bool>& visitedMap,int mode = 0);
bool checkRound(int row, int col, std::vector<std::vector<bool>>& gameMatrix,int mode);
bool canTravelTo(std::vector<std::vector<bool>>& gameMatrix, int fromRow, int fromColumn, int toRow, int toColumn)
{
    std::map<std::pair<int, int>, bool> visitedMap;
    return TravelSearch(gameMatrix, fromRow, fromColumn, toRow, toColumn, visitedMap);
}
bool TravelSearch(std::vector<std::vector<bool>>& gameMatrix, int fromRow, int fromColumn, int toRow, int toColumn, std::map<std::pair<int, int>, bool>& visitedMap, int mode)
{
    if (fromRow < 0 || fromColumn < 0 || fromRow>=gameMatrix.size() || fromColumn>=gameMatrix[0].size())return false;
    if (!gameMatrix[fromRow][fromColumn] || !gameMatrix[toRow][toColumn] || visitedMap[std::make_pair(fromRow, fromColumn)]) return false;
    if (mode && !checkRound(fromRow, fromColumn, gameMatrix, mode))return false;
    if (fromRow == toRow && fromColumn == toColumn)return true;
    visitedMap[std::make_pair(fromRow, fromColumn)] = true;
    return TravelSearch(gameMatrix, fromRow - 2, fromColumn, toRow, toColumn, visitedMap,1)||
            TravelSearch(gameMatrix, fromRow, fromColumn+1, toRow, toColumn, visitedMap)||
            TravelSearch(gameMatrix, fromRow + 2, fromColumn, toRow, toColumn, visitedMap,2)||
            TravelSearch(gameMatrix, fromRow , fromColumn-1, toRow, toColumn, visitedMap);
}
bool checkRound(int row, int col, std::vector<std::vector<bool>>& gameMatrix,int mode)
{
    if (mode == 1)
    {
        //向上
        return gameMatrix[row + 1][col];
    }
    if (mode == 2)
    {
        //向下
        return gameMatrix[row-1][col];
    }
}
#ifndef RunTests
int main()
{
    std::vector<std::vector<bool>> gameMatrix{
        {false, false, true, true, false},
        {false, false, true, false, false},
        {false, false, true, true, false},
        {false, true, false, true, false},
        {false, false, true, false, false}
    };

    std::cout << canTravelTo(gameMatrix, 2, 2, 0, 2) << std::endl;
    std::cout << canTravelTo(gameMatrix, 2, 2, 2, 1) << std::endl;
    std::cout << canTravelTo(gameMatrix, 2, 2, 2, 3) << std::endl;
    std::cout << canTravelTo(gameMatrix, 2, 2, 4, 2) << std::endl;
}
#endif
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	std::vector<int> s = { 1,23,535,123,64,21,75,234 };
	std::sort(s.begin(), s.end(), [&](int a, int b) {return a > b; });
	for (auto cur : s)
	{
		std::cout << cur << " ";
	}
}
#define _USE_MATH_DEFINES
#include <cmath>
#include <tuple>
#include <math.h>
#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>
double pi = 3.1415926;
std::pair<double, double> segmentAreas(double r, double a)
{
    double sec = pi * (r * r) * (a / 360);
    double tri = (double)1 / 2 * (r * r) * sin((a * pi) / 180);
    double sec1 = pi * (r * r) * ((360 - a) / 360);
    double tri1 = (double)1 / 2 * (r * r) * sin(((360 - a) * pi) / 180);
    return std::pair<double, double>(sec - tri, sec1 - tri1);

}

#ifndef RunTests
int main()
{
    std::pair<double, double> areas = segmentAreas(10, 90);
    std::cout << "Areas: " + std::to_string(areas.first) + ", " + std::to_string(areas.second);
}
#endif

#include <vector>
#include <iostream>

void tileEdges(std::vector<std::vector<bool>>& tiles)
{
    tiles = std::vector<std::vector<bool>>(4, std::vector<bool>(4, 0));
    for (int i = 0; i < tiles.size(); i++)
    {
        tiles[i][0] = 1;
        tiles[i][tiles[0].size() - 1] = 1;
    }
    for (int j = 0; j < tiles[0].size(); j++)
    {
        tiles[0][j] = 1;
        tiles[tiles.size() - 1][j] = 1;
    }
}

#ifndef RunTests
int main()
{
    std::vector<std::vector<bool>> tiles(4, std::vector<bool>(4));
    tileEdges(tiles);
    for (unsigned x = 0; x < tiles.size(); x++)
    {
        for (unsigned y = 0; y < tiles[x].size(); y++)
        {
            std::cout << tiles[x][y];
        }
        std::cout << std::endl;
    }
}
#endif