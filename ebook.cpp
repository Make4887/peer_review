#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class ReadStimulatingSystem {
public:
	void Read(int user, int page) {
		if (users_progress_.size() <= user) {
			users_progress_.resize(user + 1, -1);
		}
		if (count_users_readed_page_.size() <= page) {
			count_users_readed_page_.resize(page + 1);
		}
		for (int i = users_progress_[user] + 1; i <= page; ++i) {
			++count_users_readed_page_[i];
		}
		if (users_progress_[user] == -1) {
			++count_users_;
		}
		users_progress_[user] = page;
	}

	double Cheer(int user) const {
		if (users_progress_.size() <= user || users_progress_[user] == -1) {
			return 0;
		}
		if (users_progress_.size() == 2) {
			return 1;
		}
		return 1. - (count_users_readed_page_[users_progress_[user]] - 1.) / (count_users_ - 1.);
	}

private:
	std::vector<int> users_progress_;
	std::vector<int> count_users_readed_page_;
	int count_users_;
};

int main() {
	using namespace std::literals::string_literals;
	int n;
	std::cin >> n;
	ReadStimulatingSystem stimulating_system;
	for (int i = 0; i < n; ++i) {
		std::string command;
		std::cin >> command;
		if (command == "READ"s) {
			int user, page;
			std::cin >> user >> page;
			stimulating_system.Read(user, page);
		}
		else if (command == "CHEER"s) {
			int user;
			std::cin >> user;
			std::cout << std::setprecision(6) << stimulating_system.Cheer(user) << std::endl;
		}
		else {
			std::cout << "Unknown command"s << std::endl;
		}
	}
}