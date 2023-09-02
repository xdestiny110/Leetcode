/*
 * @lc app=leetcode.cn id=2512 lang=cpp
 *
 * [2512] 奖励最顶尖的 K 名学生
 */

// @lc code=start

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <optional>

struct Student
{
    int id_;
    int score_;

    bool operator>(const Student &rhs) const
    {
        return (score_ > rhs.score_) || (score_ == rhs.score_ && id_ < rhs.id_);
    }
};

class Solution
{
public:
    std::vector<int> topStudents(const std::vector<std::string> &positive_feedback, const std::vector<std::string> &negative_feedback, const std::vector<std::string> &report, const std::vector<int> &student_id, int k)
    {
        std::unordered_set<std::string_view> positive_feedback_set;
        for (const auto& feedback : positive_feedback) {
            positive_feedback_set.insert(feedback);
        }
        
        std::unordered_set<std::string_view> negative_feedback_set;
        for (const auto& feedback : negative_feedback) {
            negative_feedback_set.insert(feedback);
        }

        std::priority_queue<Student, std::vector<Student>, std::greater<Student>> q;
        for (size_t i = 0; i < student_id.size(); ++i)
        {
            int score = 0;
            score += substr_count(report[i], positive_feedback_set) * 3;
            score -= substr_count(report[i], negative_feedback_set);
            q.push({
                .id_ = student_id[i],
                .score_ = score,
            });
            while (q.size() > k)
            {
                q.pop();
            }
        }

        std::vector<int> result;
        while (!q.empty())
        {
            result.push_back(q.top().id_);
            q.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    size_t substr_count(const std::string &str, const std::unordered_set<std::string_view>& feedbacks_set) const
    {
        std::optional<size_t> last_idx = std::nullopt;
        auto str_sv = std::string_view(str);
        size_t count = 0;
        for (size_t i = 0; i < str.size(); ++i) {
            if (!last_idx.has_value()) {
                if (str[i] != ' ')
                    last_idx = i;
            } else {
                if (str[i] == ' ') {
                    auto substr_sv = str_sv.substr(*last_idx, i - *last_idx);
                    if (feedbacks_set.contains(substr_sv)) {
                        count++;
                    }
                    last_idx = std::nullopt;
                }
            }
        }
        if (last_idx.has_value()) {
            auto substr_sv = str_sv.substr(*last_idx, str.size() - *last_idx);
            if (feedbacks_set.contains(substr_sv)) {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

