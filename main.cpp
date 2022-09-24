#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <ctime>

class DelegateStrategy {
    public:
        virtual void delegate(const std::string& iTask) =0;
};

class NiceDelegateStrategy : public DelegateStrategy {
    public:
        void delegate(const std::string& iTask) override {
            std::cout << "Please " << iTask << std::endl;
        }
};

class HarshDelegateStrategy : public DelegateStrategy {
    public:
        void delegate(const std::string& iTask) override {
            std::cout << iTask << " or else...!" << std::endl;
        }
};

class Manager {
    private:
        std::unique_ptr<DelegateStrategy> _delegateStrategy;
    public:
        explicit Manager(std::unique_ptr<DelegateStrategy> iDelegateStrategy) noexcept :
        _delegateStrategy(std::move(iDelegateStrategy)) {

        }
        void start(const std::vector<std::string>& iTasks) {
            int i;
            for (i = 0; i < iTasks.size() / 2; i++) {
                std::cout << iTasks[i] << std::endl;
            }
            for (; i < iTasks.size(); i++) {
                _delegateStrategy->delegate(iTasks[i]);
            }
        }
};

int main(int argc, char** argv) {
    std::vector<std::string> aTasks;
    aTasks.push_back("do the presentation");
    aTasks.push_back("write the report");
    aTasks.push_back("fill the timesheet");
    aTasks.push_back("fix the bug");

    std::vector<std::unique_ptr<DelegateStrategy>> aDelegateStrategies;
    aDelegateStrategies.push_back(std::make_unique<NiceDelegateStrategy>());
    aDelegateStrategies.push_back(std::make_unique<HarshDelegateStrategy>());

    srand((unsigned)time(0));

    Manager aManager(std::move(aDelegateStrategies[rand() % 2]));
    aManager.start(aTasks);
    return 0;
}