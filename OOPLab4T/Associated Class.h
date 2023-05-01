class ContactList {
private:
    map<string, pair<string, string>> contacts;
    string error_message;

public:
    ContactList() {}
    pair<string, string> operator[](string name) {
        if (contacts.find(name) != contacts.end()) {
            return contacts[name];
        }
        else {
            error_message = "Contact not found";
            return make_pair("", "");
        }
    }

    void operator()(string name, string email, string phone) {
        contacts[name] = make_pair(email, phone);
    }

    void print() {
        cout << "Contacts:\n";
        for (const auto& contact : contacts) {
            cout << contact.first << ": " << contact.second.first << ", " << contact.second.second << "\n";
        }
    }

    friend istream& operator>>(istream& in, ContactList& cl) {
        string name, email, phone;
        cout << "Enter contact name: ";
        in >> name;
        cout << "Enter email: ";
        in >> email;
        cout << "Enter phone number: ";
        in >> phone;
        cl(name, email, phone);
        return in;
    }

    friend ostream& operator<<(ostream& out, ContactList& cl) {
        out << "Contacts:\n";
        for (const auto& contact : cl.contacts) {
            out << contact.first << ": " << contact.second.first << ", " << contact.second.second << "\n";
        }
        return out;
    }
};
