#include <iostream>
#include <vector>

class BrowserHistory {
private:
    std::vector<std::string> history;
    int current;

public:
    BrowserHistory(std::string homepage) {
        history.push_back(homepage);
        current = 0;
    }
    
    void visit(std::string url) {
        history.resize(current + 1);
        history.push_back(url);
        current++;
    }
    
    std::string back(int steps) {
        current = std::max(0, current - steps);
        return history[current];
    }
    
    std::string forward(int steps) {
        current = std::min(static_cast<int>(history.size()) - 1, current + steps);
        return history[current];
    }
};

int main() {

    BrowserHistory browser("leetcode.com");
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    std::cout << browser.back(1) << std::endl;
    std::cout << browser.back(1) << std::endl;
    std::cout << browser.forward(1) << std::endl;
    browser.visit("linkedin.com");
    std::cout << browser.forward(2) << std::endl;  
    std::cout << browser.back(2) << std::endl;     
    std::cout << browser.back(7) << std::endl;  

    return 0;
}
