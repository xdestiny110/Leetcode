/*
 * @lc app=leetcode.cn id=1600 lang=cpp
 *
 * [1600] 王位继承顺序
 */

// @lc code=start

#include <list>
#include <vector>
#include <string>
#include <unordered_map>

struct Successor {
    std::string name_;
    std::vector<Successor*> children_;
    bool alive_ = true;
};

class ThroneInheritance {
public:
    ThroneInheritance(std::string kingName) : kind_name_(std::move(kingName)) {
        successors_.emplace(kind_name_, Successor {.name_ = kind_name_});
    }
    
    void birth(std::string parentName, std::string childName) {
        successors_.emplace(childName, Successor {.name_ = childName});
        successors_[parentName].children_.push_back(&successors_[childName]);
    }
    
    void death(std::string name) {
        successors_[name].alive_ = false;
    }
    
    std::vector<std::string> getInheritanceOrder() {
        std::vector<std::string> result;
        result.reserve(successors_.size());
        travel_successors(result, successors_[kind_name_]);
        return result;
    }

private:
    std::unordered_map<std::string, Successor> successors_;
    std::string kind_name_;

    void travel_successors(std::vector<std::string>& result, const Successor& succesor) {
        if (succesor.alive_)
            result.push_back(succesor.name_);
        for (auto child : succesor.children_) {
            travel_successors(result, *child);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
// @lc code=end

