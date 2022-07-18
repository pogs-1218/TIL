#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string solution(std::vector<std::string> participant,
                     std::vector<std::string> completion) {
  std::string answer = "";

  std::map<std::string, int> running_members;
  for (const auto& member : participant) {
    ++running_members[member];
  }
  for (const auto& member : completion) {
    if (running_members.find(member) != running_members.end()) {
      --running_members[member];
    }
  }
  for (const auto& member : running_members) {
    if (member.second != 0) {
      answer = member.first;
    }
  }

  return answer;
}

int main() {
  std::vector<std::string> participant1{"leo", "kiki", "eden"};
  std::vector<std::string> completion1{"eden", "kiki"};

  std::vector<std::string> participant2{"marina", "josipa", "nikola", "vinko",
                                        "filipa"};
  std::vector<std::string> completion2{"josipa", "filipa", "marina", "nikola"};

  std::vector<std::string> participant3{"mislav", "stanko", "mislav", "ana"};
  std::vector<std::string> completion3{"stanko", "ana", "mislav"};

  std::cout << solution(participant1, completion1) << std::endl;
  std::cout << solution(participant2, completion2) << std::endl;
  std::cout << solution(participant3, completion3) << std::endl;

  return 0;
}