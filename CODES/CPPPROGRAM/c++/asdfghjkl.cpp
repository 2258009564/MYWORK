#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <optional>
#include <iomanip>
#include <map>
#include <sstream>
#include <chrono>
#include <ctime>
#include <regex>

// 用于控制台输出的颜色定义
namespace Color
{
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m"; 
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
}

// 商品类别
enum class Category
{
    Pen = 1,
    Book,
    Paint,
    Other
};

// 商品品牌
enum class Brand
{
    Chenguang = 1,
    Deli,
    Banma,
    Baile,
    Other
};

// 用于类型转换的工具类
class EnumConverter
{
public:
    static std::string categoryToString(Category cat)
    {
        static const std::map<Category, std::string> categoryMap = {
            {Category::Pen, "笔"},
            {Category::Book, "本"},
            {Category::Paint, "颜料"},
            {Category::Other, "其他"}};
        return categoryMap.at(cat);
    }

    static std::string brandToString(Brand brand)
    {
        static const std::map<Brand, std::string> brandMap = {
            {Brand::Chenguang, "晨光"},
            {Brand::Deli, "得力"},
            {Brand::Banma, "斑马"},
            {Brand::Baile, "百乐"},
            {Brand::Other, "其他"}};
        return brandMap.at(brand);
    }

    static Category stringToCategory(const std::string &str)
    {
        static const std::map<std::string, Category> categoryMap = {
            {"笔", Category::Pen},
            {"本", Category::Book},
            {"颜料", Category::Paint},
            {"其他", Category::Other}};
        return categoryMap.at(str);
    }

    static Brand stringToBrand(const std::string &str)
    {
        static const std::map<std::string, Brand> brandMap = {
            {"晨光", Brand::Chenguang},
            {"得力", Brand::Deli},
            {"斑马", Brand::Banma},
            {"百乐", Brand::Baile},
            {"其他", Brand::Other}};
        return brandMap.at(str);
    }
};

// 商品类
class Thing
{
public:
    Thing(int id, std::string name, Category cate, Brand brand, double price, int num)
        : id_(id), name_(std::move(name)), category_(cate), brand_(brand),
          price_(price), num_(num), createTime_(std::chrono::system_clock::now()) {}

    // Getters
    int getId() const { return id_; }
    const std::string &getName() const { return name_; }
    Category getCategory() const { return category_; }
    Brand getBrand() const { return brand_; }
    double getPrice() const { return price_; }
    int getNum() const { return num_; }
    std::chrono::system_clock::time_point getCreateTime() const { return createTime_; }

    // Setters
    void setName(const std::string &name) { name_ = name; }
    void setCategory(Category cate) { category_ = cate; }
    void setBrand(Brand brand) { brand_ = brand; }
    void setPrice(double price)
    {
        if (price < 0)
            throw std::invalid_argument("价格不能为负数");
        price_ = price;
    }
    void setNum(int num)
    {
        if (num < 0)
            throw std::invalid_argument("数量不能为负数");
        num_ = num;
    }

    // 格式化输出
    std::string toString() const
    {
        std::stringstream ss;
        ss << "商品ID: " << id_ << "\n"
           << "名称: " << name_ << "\n"
           << "类别: " << EnumConverter::categoryToString(category_) << "\n"
           << "品牌: " << EnumConverter::brandToString(brand_) << "\n"
           << "单价: " << std::fixed << std::setprecision(2) << price_ << "\n"
           << "库存: " << num_ << "\n"
           << "创建时间: " << getFormattedTime();
        return ss.str();
    }

private:
    int id_;
    std::string name_;
    Category category_;
    Brand brand_;
    double price_;
    int num_;
    std::chrono::system_clock::time_point createTime_;

    std::string getFormattedTime() const
    {
        auto time = std::chrono::system_clock::to_time_t(createTime_);
        std::string timeStr = std::ctime(&time);
        return timeStr.substr(0, timeStr.length() - 1); // 移除末尾的换行符
    }
};

// 自定义异常类
class StoreException : public std::runtime_error
{
public:
    explicit StoreException(const std::string &message)
        : std::runtime_error(message) {}
};

class InputValidator
{
public:
    static bool isValidId(const std::string &id)
    {
        static const std::regex idPattern("^[0-9]{1,6}$");
        return std::regex_match(id, idPattern);
    }

    static bool isValidName(const std::string &name)
    {
        return !name.empty() && name.length() <= 20;
    }

    static bool isValidPrice(const std::string &price)
    {
        static const std::regex pricePattern("^[0-9]+(\\.[0-9]{1,2})?$");
        return std::regex_match(price, pricePattern);
    }

    static bool isValidNumber(const std::string &num)
    {
        static const std::regex numPattern("^[0-9]{1,5}$");
        return std::regex_match(num, numPattern);
    }
};

// StoreManager.hpp
class StoreManager
{
public:
    StoreManager(const std::string &filename = "store.txt")
        : filename_(filename), isModified_(false)
    {
        loadFromFile();
    }

    ~StoreManager()
    {
        if (isModified_)
        {
            try
            {
                saveToFile();
            }
            catch (const std::exception &e)
            {
                std::cerr << "保存文件时发生错误: " << e.what() << std::endl;
            }
        }
    }

    // 添加商品
    void addThing(const Thing &thing)
    {
        if (findById(thing.getId()))
        {
            throw StoreException("商品ID已存在");
        }
        if (things_.size() >= MAX_ITEMS)
        {
            throw StoreException("商品数量已达到上限");
        }
        things_.push_back(thing);
        isModified_ = true;
        logOperation("添加商品", thing.getId());
    }

    // 批量导入商品
    void importFromFile(const std::string &importFile)
    {
        std::ifstream file(importFile);
        if (!file)
        {
            throw StoreException("无法打开导入文件");
        }

        std::vector<Thing> tempThings;
        std::string line;
        int lineNum = 0;

        while (std::getline(file, line))
        {
            lineNum++;
            try
            {
                auto thing = parseLine(line);
                if (findById(thing.getId()))
                {
                    std::cerr << "警告: 第" << lineNum << "行的商品ID已存在，已跳过\n";
                    continue;
                }
                tempThings.push_back(thing);
            }
            catch (const std::exception &e)
            {
                std::cerr << "警告: 第" << lineNum << "行解析失败: " << e.what() << "\n";
            }
        }

        // 批量添加成功解析的商品
        for (const auto &thing : tempThings)
        {
            things_.push_back(thing);
        }

        isModified_ = true;
        logOperation("批量导入", tempThings.size());
    }

    // 按ID查找商品
    std::optional<Thing> findById(int id) const
    {
        auto it = std::find_if(things_.begin(), things_.end(),
                               [id](const Thing &t)
                               { return t.getId() == id; });
        if (it != things_.end())
        {
            return *it;
        }
        return std::nullopt;
    }

    // 按名称查找商品
    std::vector<Thing> findByName(const std::string &name) const
    {
        std::vector<Thing> result;
        std::copy_if(things_.begin(), things_.end(), std::back_inserter(result),
                     [&name](const Thing &t)
                     {
                         return t.getName().find(name) != std::string::npos;
                     });
        return result;
    }

    // 按类别查找商品
    std::vector<Thing> findByCategory(Category category) const
    {
        std::vector<Thing> result;
        std::copy_if(things_.begin(), things_.end(), std::back_inserter(result),
                     [category](const Thing &t)
                     { return t.getCategory() == category; });
        return result;
    }

    // 按品牌查找商品
    std::vector<Thing> findByBrand(Brand brand) const
    {
        std::vector<Thing> result;
        std::copy_if(things_.begin(), things_.end(), std::back_inserter(result),
                     [brand](const Thing &t)
                     { return t.getBrand() == brand; });
        return result;
    }

    // 删除商品
    bool removeThing(int id)
    {
        auto it = std::find_if(things_.begin(), things_.end(),
                               [id](const Thing &t)
                               { return t.getId() == id; });
        if (it != things_.end())
        {
            things_.erase(it);
            isModified_ = true;
            logOperation("删除商品", id);
            return true;
        }
        return false;
    }

    // 修改商品
    bool updateThing(int id, const std::function<void(Thing &)> &updateFunc)
    {
        auto it = std::find_if(things_.begin(), things_.end(),
                               [id](const Thing &t)
                               { return t.getId() == id; });
        if (it != things_.end())
        {
            try
            {
                updateFunc(*it);
                isModified_ = true;
                logOperation("修改商品", id);
                return true;
            }
            catch (const std::exception &e)
            {
                throw StoreException(std::string("修改失败: ") + e.what());
            }
        }
        return false;
    }

    // 按价格排序
    void sortByPrice(bool ascending = true)
    {
        if (ascending)
        {
            std::sort(things_.begin(), things_.end(),
                      [](const Thing &a, const Thing &b)
                      { return a.getPrice() < b.getPrice(); });
        }
        else
        {
            std::sort(things_.begin(), things_.end(),
                      [](const Thing &a, const Thing &b)
                      { return a.getPrice() > b.getPrice(); });
        }
    }

    // 统计分析
    struct Statistics
    {
        int totalItems;
        double totalValue;
        std::map<Category, int> categoryCount;
        std::map<Brand, int> brandCount;
        std::map<Category, double> categoryValue; // 新增:按类别统计总值
        std::map<Category, int> categoryItems;    // 新增:按类别统计数量
    };

    Statistics getStatistics() const
    {
        Statistics stats{0, 0.0};
        for (const auto &thing : things_)
        {
            int itemCount = thing.getNum();
            double itemValue = thing.getPrice() * itemCount;
            
            stats.totalItems += itemCount;
            stats.totalValue += itemValue;
            stats.categoryCount[thing.getCategory()]++;
            stats.brandCount[thing.getBrand()]++;
            
            // 新增:按类别累计总值和数量
            stats.categoryValue[thing.getCategory()] += itemValue;
            stats.categoryItems[thing.getCategory()] += itemCount;
        }
        return stats;
    }

    // 获取所有商品
    const std::vector<Thing> &getAllThings() const
    {
        return things_;
    }

private:
    static constexpr size_t MAX_ITEMS = 1000;
    std::vector<Thing> things_;
    std::string filename_;
    bool isModified_;

    void loadFromFile()
    {
        std::ifstream file(filename_);
        if (!file)
        {
            return; // 文件不存在时创建新文件
        }

        things_.clear();
        std::string line;
        while (std::getline(file, line))
        {
            try
            {
                things_.push_back(parseLine(line));
            }
            catch (const std::exception &e)
            {
                std::cerr << "读取文件时发生错误: " << e.what() << std::endl;
            }
        }
    }

    void saveToFile() const
    {
        std::ofstream file(filename_);
        if (!file)
        {
            throw StoreException("无法打开文件进行保存");
        }

        for (const auto &thing : things_)
        {
            file << thing.getId() << "|"
                 << thing.getName() << "|"
                 << static_cast<int>(thing.getCategory()) << "|"
                 << static_cast<int>(thing.getBrand()) << "|"
                 << std::fixed << std::setprecision(2) << thing.getPrice() << "|"
                 << thing.getNum() << "\n";
        }
    }

    Thing parseLine(const std::string &line)
    {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> items;

        while (std::getline(ss, item, '|'))
        {
            items.push_back(item);
        }

        if (items.size() != 6)
        {
            throw StoreException("无效的数据格式");
        }

        return Thing(
            std::stoi(items[0]),
            items[1],
            static_cast<Category>(std::stoi(items[2])),
            static_cast<Brand>(std::stoi(items[3])),
            std::stod(items[4]),
            std::stoi(items[5]));
    }

    void logOperation(const std::string &operation, int id)
    {
        std::ofstream logFile("store_log.txt", std::ios::app);
        if (logFile)
        {
            auto now = std::chrono::system_clock::now();
            auto time = std::chrono::system_clock::to_time_t(now);
            logFile << std::ctime(&time) << operation << " ID:" << id << std::endl;
        }
    }
};

// UserInterface.hpp
class UserInterface
{
public:
    UserInterface() : store_("store.txt")
    {
        initializeCommands();
    }

    void run()
    {
        while (true)
        {
            try
            {
                showMainMenu();
                int choice = getMenuChoice();
                if (choice == 0)
                {
                    if (confirmExit())
                    {
                        std::cout << "\n感谢使用本系统，再见！\n";
                        break;
                    }
                    continue;
                }
                executeCommand(choice);
            }
            catch (const std::exception &e)
            {
                std::cerr << Color::RED << "\n错误: " << e.what() << Color::RESET << std::endl;
                pauseAndClear();
            }
        }
    }

private:
    StoreManager store_;
    std::map<int, std::function<void()>> commands_;

    void initializeCommands()
    {
        commands_ = {
            {1, [this]()
             { batchImport(); }},
            {2, [this]()
             { browseAll(); }},
            {3, [this]()
             { searchItems(); }},
            {4, [this]()
             { addItem(); }},
            {5, [this]()
             { deleteItem(); }},
            {6, [this]()
             { modifyItem(); }},
            {7, [this]()
             { statisticsByCategory(); }},
            {8, [this]()
             { sortByPrice(); }},
            {9, [this]()
             { calculateTotalValue(); }}};
    }

    // ... 后续将继续实现具体的界面方法// UserInterface.hpp 继续

private:
    void showMainMenu() const
    {
        std::cout << Color::CYAN;
        std::cout << "\n=================================\n";
        std::cout << "    文具店商品管理系统 V2.0\n";
        std::cout << "=================================\n";
        std::cout << Color::RESET;
        std::cout << " 1. 批量导入商品信息\n";
        std::cout << " 2. 浏览所有商品\n";
        std::cout << " 3. 查询商品信息\n";
        std::cout << " 4. 添加新商品\n";
        std::cout << " 5. 删除商品\n";
        std::cout << " 6. 修改商品信息\n";
        std::cout << " 7. 类别统计\n";
        std::cout << " 8. 价格排序\n";
        std::cout << " 9. 计算库存总值\n";
        std::cout << " 0. 退出系统\n";
        std::cout << "=================================\n";
    }

    int getMenuChoice() const
    {
        std::string input;
        while (true)
        {
            std::cout << "\n请输入您的选择 (0-9): ";
            std::getline(std::cin, input);

            if (input.length() == 1 && input[0] >= '0' && input[0] <= '9')
            {
                return input[0] - '0';
            }
            std::cout << Color::RED << "无效的输入，请重试！" << Color::RESET << std::endl;
        }
    }

    void executeCommand(int choice)
    {
        auto it = commands_.find(choice);
        if (it != commands_.end())
        {
            it->second();
        }
        else
        {
            throw StoreException("无效的选择");
        }
    }

    void batchImport()
    {
        std::cout << "\n=== 批量导入商品信息 ===\n";
        std::cout << "请输入要导入的文件名: ";
        std::string filename;
        std::getline(std::cin, filename);

        try
        {
            store_.importFromFile(filename);
            std::cout << Color::GREEN << "导入成功！" << Color::RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            throw StoreException(std::string("导入失败: ") + e.what());
        }
        pauseAndClear();
    }

    void browseAll()
    {
        std::cout << "\n=== 所有商品信息 ===\n";
        const auto &things = store_.getAllThings();
        if (things.empty())
        {
            std::cout << "当前没有任何商品。\n";
        }
        else
        {
            displayThings(things);
        }
        pauseAndClear();
    }

    void searchItems()
    {
        std::cout << "\n=== 查询商品信息 ===\n";
        std::cout << "1. 按编号查询\n";
        std::cout << "2. 按名称查询\n";
        std::cout << "3. 按类别查询\n";
        std::cout << "4. 按品牌查询\n";

        int choice = getValidNumber("请选择查询方式(1-4): ", 1, 4);

        switch (choice)
        {
        case 1:
            searchById();
            break;
        case 2:
            searchByName();
            break;
        case 3:
            searchByCategory();
            break;
        case 4:
            searchByBrand();
            break;
        }
    }

    void searchById()
    {
        int id = getValidNumber("请输入商品编号: ", 1, 999999);
        auto thing = store_.findById(id);
        if (thing)
        {
            std::cout << "\n找到商品：\n"
                      << thing->toString() << std::endl;
        }
        else
        {
            std::cout << Color::YELLOW << "未找到该商品。" << Color::RESET << std::endl;
        }
        pauseAndClear();
    }

    void searchByName()
    {
        std::cout << "请输入商品名称: ";
        std::string name;
        std::getline(std::cin, name);

        auto things = store_.findByName(name);
        if (!things.empty())
        {
            displayThings(things);
        }
        else
        {
            std::cout << Color::YELLOW << "未找到相关商品。" << Color::RESET << std::endl;
        }
        pauseAndClear();
    }

    void searchByCategory()
    {
        displayCategoryMenu();
        int choice = getValidNumber("请选择类别(1-4): ", 1, 4);
        auto things = store_.findByCategory(static_cast<Category>(choice));
        if (!things.empty())
        {
            displayThings(things);
        }
        else
        {
            std::cout << Color::YELLOW << "该类别下没有商品。" << Color::RESET << std::endl;
        }
        pauseAndClear();
    }

    void searchByBrand()
    {
        displayBrandMenu();
        int choice = getValidNumber("请选择品牌(1-5): ", 1, 5);
        auto things = store_.findByBrand(static_cast<Brand>(choice));
        if (!things.empty())
        {
            displayThings(things);
        }
        else
        {
            std::cout << Color::YELLOW << "该品牌下没有商品。" << Color::RESET << std::endl;
        }
        pauseAndClear();
    }

    void addItem()
    {
        std::cout << "\n=== 添加新商品 ===\n";

        int id = getValidNumber("请输入商品编号(1-999999): ", 1, 999999);
        if (store_.findById(id))
        {
            throw StoreException("该商品编号已存在！");
        }

        std::cout << "请输入商品名称: ";
        std::string name;
        std::getline(std::cin, name);
        if (!InputValidator::isValidName(name))
        {
            throw StoreException("商品名称无效！");
        }

        displayCategoryMenu();
        int category = getValidNumber("请选择商品类别(1-4): ", 1, 4);

        displayBrandMenu();
        int brand = getValidNumber("请选择商品品牌(1-5): ", 1, 5);

        double price = getValidDouble("请输入商品单价: ", 0.01, 99999.99);
        int num = getValidNumber("请输入库存数量: ", 0, 99999);

        Thing newThing(id, name, static_cast<Category>(category),
                       static_cast<Brand>(brand), price, num);
        store_.addThing(newThing);

        std::cout << Color::GREEN << "\n商品添加成功！" << Color::RESET << std::endl;
        pauseAndClear();
    }

    void deleteItem()
    {
        std::cout << "\n=== 删除商品 ===\n";
        int id = getValidNumber("请输入要删除的商品编号: ", 1, 999999);

        auto thing = store_.findById(id);
        if (!thing)
        {
            throw StoreException("未找到该商品！");
        }

        std::cout << "\n要删除的商品信息：\n"
                  << thing->toString() << std::endl;
        if (confirmAction("确定要删除这个商品吗？(Y/N): "))
        {
            store_.removeThing(id);
            std::cout << Color::GREEN << "商品删除成功！" << Color::RESET << std::endl;
        }
        else
        {
            std::cout << "已取消删除操作。" << std::endl;
        }
        pauseAndClear();
    }

    void modifyItem()
    {
        std::cout << "\n=== 修改商品信息 ===\n";
        int id = getValidNumber("请输入要修改的商品编号: ", 1, 999999);

        auto thing = store_.findById(id);
        if (!thing)
        {
            throw StoreException("未找到该商品！");
        }

        std::cout << "\n当前商品信息：\n"
                  << thing->toString() << std::endl;

        std::cout << "\n请选择要修改的项目：\n";
        std::cout << "1. 商品名称\n";
        std::cout << "2. 商品类别\n";
        std::cout << "3. 商品品牌\n";
        std::cout << "4. 商品单价\n";
        std::cout << "5. 库存数量\n";

        int choice = getValidNumber("请选择(1-5): ", 1, 5);

        store_.updateThing(id, [this, choice](Thing &t)
                           {
            switch (choice) {
                case 1: {
                    std::cout << "请输入新的商品名称: ";
                    std::string name;
                    std::getline(std::cin, name);
                    if (!InputValidator::isValidName(name)) {
                        throw StoreException("商品名称无效！");
                    }
                    t.setName(name);
                    break;
                }
                case 2: {
                    displayCategoryMenu();
                    int category = getValidNumber("请选择新的商品类别(1-4): ", 1, 4);
                    t.setCategory(static_cast<Category>(category));
                    break;
                }
                case 3: {
                    displayBrandMenu();
                    int brand = getValidNumber("请选择新的商品品牌(1-5): ", 1, 5);
                    t.setBrand(static_cast<Brand>(brand));
                    break;
                }
                case 4: {
                    double price = getValidDouble("请输入新的商品单价: ", 0.01, 99999.99);
                    t.setPrice(price);
                    break;
                }
                case 5: {
                    int num = getValidNumber("请输入新的库存数量: ", 0, 99999);
                    t.setNum(num);
                    break;
                }
            } });

        std::cout << Color::GREEN << "\n修改成功！" << Color::RESET << std::endl;
        pauseAndClear();
    }

    void statisticsByCategory()
    {
        std::cout << "\n=== 商品类别统计 ===\n";
        auto stats = store_.getStatistics();

        std::cout << std::setw(10) << "类别"
                  << std::setw(15) << "商品种类"
                  << std::setw(15) << "库存总量"
                  << std::setw(15) << "库存总值" << std::endl;
        std::cout << std::string(55, '-') << std::endl;

        for (const auto &[category, count] : stats.categoryCount)
        {
            std::cout << std::setw(10) << EnumConverter::categoryToString(category)
                      << std::setw(15) << count
                      << std::setw(15) << stats.categoryItems[category]
                      << std::setw(15) << std::fixed << std::setprecision(2) 
                      << stats.categoryValue[category] << std::endl;
        }

        pauseAndClear();
    }

    void sortByPrice()
    {
        std::cout << "\n=== 价格排序 ===\n";
        std::cout << "1. 按价格升序\n";
        std::cout << "2. 按价格降序\n";

        int choice = getValidNumber("请选择排序方式(1-2): ", 1, 2);
        store_.sortByPrice(choice == 1);

        std::cout << "\n排序后的商品列表：\n";
        browseAll();
    }

    void calculateTotalValue()
    {
        std::cout << "\n=== 库存总值统计 ===\n";
        auto stats = store_.getStatistics();

        std::cout << "商品总种类：" << store_.getAllThings().size() << std::endl;
        std::cout << "商品总数量：" << stats.totalItems << std::endl;
        std::cout << "库存总价值：" << std::fixed << std::setprecision(2)
                  << stats.totalValue << " 元" << std::endl;

        pauseAndClear();
    }

    // 辅助方法
    void displayThings(const std::vector<Thing> &things) const
    {
        std::cout << std::setw(8) << "编号"
                  << std::setw(20) << "名称"
                  << std::setw(10) << "类别"
                  << std::setw(10) << "品牌"
                  << std::setw(12) << "单价"
                  << std::setw(10) << "库存" << std::endl;
        std::cout << std::string(70, '-') << std::endl;

        for (const auto &thing : things)
        {
            std::cout << std::setw(8) << thing.getId()
                      << std::setw(20) << thing.getName()
                      << std::setw(10) << EnumConverter::categoryToString(thing.getCategory())
                      << std::setw(10) << EnumConverter::brandToString(thing.getBrand())
                      << std::setw(12) << std::fixed << std::setprecision(2) << thing.getPrice()
                      << std::setw(10) << thing.getNum() << std::endl;
        }
    }

    void displayCategoryMenu() const
    {
        std::cout << "\n商品类别：\n";
        std::cout << "1. 笔\n";
        std::cout << "2. 本\n";
        std::cout << "3. 颜料\n";
        std::cout << "4. 其他\n";
    }

    void displayBrandMenu() const
    {
        std::cout << "\n商品品牌：\n";
        std::cout << "1. 晨光\n";
        std::cout << "2. 得力\n";
        std::cout << "3. 斑马\n";
        std::cout << "4. 百乐\n";
        std::cout << "5. 其他\n";
    }

    int getValidNumber(const std::string &prompt, int min, int max) const
    {
        while (true)
        {
            std::cout << prompt;
            std::string input;
            std::getline(std::cin, input);

            try
            {
                int number = std::stoi(input);
                if (number >= min && number <= max)
                {
                    return number;
                }
            }
            catch (...)
            {
            }

            std::cout << Color::RED << "请输入" << min << "-" << max << "之间的数字！"
                      << Color::RESET << std::endl;
        }
    }

    double getValidDouble(const std::string &prompt, double min, double max) const
    {
        while (true)
        {
            std::cout << prompt;
            std::string input;
            std::getline(std::cin, input);

            try
            {
                double number = std::stod(input);
                if (number >= min && number <= max)
                {
                    return number;
                }
            }
            catch (...)
            {
            }

            std::cout << Color::RED << "请输入" << min << "-" << max << "之间的数字！"
                      << Color::RESET << std::endl;
        }
    }

    bool confirmAction(const std::string &prompt) const
    {
        while (true)
        {
            std::cout << prompt;
            std::string input;
            std::getline(std::cin, input);

            if (input == "Y" || input == "y")
                return true;
            if (input == "N" || input == "n")
                return false;

            std::cout << "请输入 Y 或 N！" << std::endl;
        }
    }

    bool confirmExit() const
    {
        return confirmAction("确定要退出系统吗？(Y/N): ");
    }

    void pauseAndClear() const
    {
        std::cout << "\n按回车键继续...";
        std::cin.get();
        system("clear"); // 在 Windows 系统上使用 "cls"
    }
};

// main.cpp
int main()
{
    try
    {
        UserInterface ui;
        ui.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "程序发生严重错误: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}