#include <iostream>
#include <stdexcept>
#include <string>

class DatabaseException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};

class QueryTimeoutException : public DatabaseException {};

template <typename T>
class DatabaseConnector {
public:
    void connect(const std::string& dbName) {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw DatabaseException();
        }
    }

    void executeQuery(const std::string& query) {
        if (query.find("timeout") != std::string::npos) {
            throw QueryTimeoutException();
        }
    }
};

int main() {
    DatabaseConnector<int> connector;

    try {
        std::cout << "Attempting to connect to invalid_db...\n";
        connector.connect("invalid_db");
    } catch (const ConnectionFailedException& e) {
        std::cout << "Caught ConnectionFailedException - what(): " << e.what() << "\n";
    } catch (const DatabaseException& e) {
        std::cout << "Caught a general DatabaseException - what(): " << e.what() << "\n";
    }

    try {
        std::cout << "\nAttempting to connect to slow_db...\n";
        connector.connect("slow_db");
    } catch (const ConnectionFailedException& e) {
        std::cout << "Caught ConnectionFailedException - what(): " << e.what() << "\n";
    } catch (const DatabaseException& e) {
        std::cout << "Caught a general DatabaseException - what(): " << e.what() << "\n";
    }

    try {
        std::cout << "\nAttempting to execute timeout query...\n";
        connector.executeQuery("SELECT * FROM large_table timeout");
    } catch (const QueryTimeoutException& e) {
        std::cout << "Caught QueryTimeoutException - what(): " << e.what() << "\n";
    }

    return 0;
}
