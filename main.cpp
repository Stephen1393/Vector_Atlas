 #include <iostream>
 #include <string>
 #include <cctype>

int main() {

    std::string message = "Good afternoon. I hear we're having another heatwave.";
    int words = 0;

    for (int i{0}; i < message.size(); ++i) {
        char letter = message[i];
        
        if (
            (letter == ' ') ||
            (i == message.size() - 1) 
        )
        {
            words++; 
        }
    }

    std:: cout << "words: " << words << '\n';
}

