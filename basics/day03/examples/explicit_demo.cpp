#include <iostream>

class Score {
public:
    explicit Score(int value)
        : value_(value) {}

    int value() const {
        return value_;
    }

private:
    int value_;
};

void print_score(Score score) {
    std::cout << "score: " << score.value() << '\n';
}

int main() {
    Score a(90);
    print_score(a);

    print_score(Score(95));

    // Because Score(int) is explicit, this will not compile:
    // print_score(100);

    return 0;
}
