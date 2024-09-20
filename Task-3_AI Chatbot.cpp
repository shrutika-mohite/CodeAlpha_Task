#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Chatbot {
public:
    Chatbot() {}

    void startConversation() {
        std::string userInput;
        std::cout << "Chatbot: Hello! How can I assist you today?" << std::endl;

        while (true) {
            std::cout << "You: ";
            std::getline(std::cin, userInput);
            if (userInput == "exit") {
                std::cout << "Chatbot: Goodbye!" << std::endl;
                break;
            }
            manageDialogue(userInput);
        }
    }

private:
    void manageDialogue(const std::string& input) {
        std::string sentiment = analyzeSentiment(input);
        std::string response = getResponse(input);
        
        std::cout << "Chatbot: [Sentiment: " << sentiment << "] " << response << std::endl;
    }

    std::string analyzeSentiment(const std::string& input) {
        // Very simplistic sentiment analysis
        if (input.find("happy") != std::string::npos) return "positive";
        if (input.find("sad") != std::string::npos) return "negative";
        return "neutral";
    }

    std::string getResponse(const std::string& input) {
        std::vector<std::string> tokens = tokenize(input);
        
        if (std::find(tokens.begin(), tokens.end(), "help") != tokens.end()) {
            return "I'm here to help! What do you need assistance with?";
        } else if (std::find(tokens.begin(), tokens.end(), "weather") != tokens.end()) {
            return "I can't check the weather right now, but you can look it up online!";
        } else {
            return "That's interesting! Tell me more.";
        }
    }

    std::vector<std::string> tokenize(const std::string& input) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(input);

        while (std::getline(tokenStream, token, ' ')) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

int main() {
    Chatbot chatbot;
    chatbot.startConversation();
    return 0;
}

