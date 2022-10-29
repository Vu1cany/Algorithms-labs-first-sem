    #include <iostream>


    using namespace std;

     struct Fridge {
        int milk;
        int meat;
        int cheese;
        int chocolate;
        void Add_Meat(int add_var) {
            if (add_var >= 0) {
                meat += add_var;
            } else { cout << "WARNiNG: Non-correct value: " << add_var << endl; }
        }
        void Add_Milk(int add_var) {
            if (add_var >= 0) {
                milk += add_var;
            } else { cout << "WARNiNG: Non-correct value: " << add_var << endl; }
        }
        void Add_Cheese(int add_var) {
            if (add_var >= 0) {
                cheese += add_var;
            } else { cout << "WARNiNG: Non-correct value: " << add_var << endl; }
        }
        void Add_Chocolate(int add_var) {
            if (add_var >= 0) {
                chocolate += add_var;
            } else { cout << "WARNiNG: Non-correct value: " << add_var << endl; }
        }
        void Get_Meat(int get_var) {
            if (get_var >= 0) {
                if (get_var < meat) {
                    meat -= get_var;
                } else { meat = 0; }
            } else { cout << "WARNiNG: Non-correct value: " << get_var << endl; }
        }
        void Get_Milk(int get_var) {
            if (get_var >= 0) {
                if (get_var < milk) {
                    milk -= get_var;
                } else { milk = 0; }
            } else { cout << "WARNiNG: Non-correct value: " << get_var << endl; }
        }
        void Get_Cheese(int get_var) {
            if (get_var >= 0) {
                if (get_var < cheese) {
                    cheese -= get_var;
                } else { cheese = 0; }
            } else { cout << "WARNiNG: Non-correct value: " << get_var << endl; }
        }
        void Get_Chocolate(int get_var) {
            if (get_var >= 0) {
                if (get_var < chocolate) {
                    chocolate -= get_var;
                } else { chocolate = 0; }
            } else { cout << "WARNiNG: Non-correct value: " << get_var << endl; }
        }
        void Info() {
            cout << "Milk: " << milk << " liters" << endl;
            cout << "Meat: " << meat << " kg" << endl;
            cout << "Cheese: " << cheese << " pieces" << endl;
            cout << "Chocolate: " << chocolate << " pieces" << endl;
        }
    };

    int main() {
        Fridge Fridge1 {2, 3, 10, 2};
        Fridge Fridge2 {0, 5, 1, 11};

        Fridge1.Info();
        Fridge1.Add_Milk(-3);
        Fridge1.Add_Cheese(1);
        Fridge1.Get_Meat(Fridge1.meat);
        Fridge1.Get_Chocolate(-2);
        Fridge1.Info();


    }