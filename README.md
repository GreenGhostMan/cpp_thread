# cpp thread
- g++ -std=c++11 -pthread blabla.cpp
- thread လုပ်တိုင်းလဲ ပိုမြန်ရမယ်ဆိုလိုတာ မဟုတ်ဘူး
- multipile thread တွေသုံးထားရင် ဘယ်ကောင်အရင် run မလဲ အာမ မခံဘူး

- thread ကို နည်း၅ မျိုးနဲ့သုံးနိုင်ပါတယ်။

#### 1 function pointer နည်း
void fun(int x) {
    while(x-->0) { cout << x << endl; }
}
int main() {
    std::thread t1(fun,10);
    t1.join();
    return 0;
}

#### 2 Lambda function 

int main() {
    auto fun = [] (int x) {
        while(x-->0) { cout << x << endl; }
    };

    std::thread t(fun,10);
    t.join();
    return 0;
}

#### 3 Functor
class Base{
    public:
        void operator () (int x) {
            while(x-->0) {
                cout << x << endl;
            }
        }
};
int main() {
 
    std::thread t( (Base()), 10);
    t.join();
    return 0;
}

#### 4 member function
class Base{
    public:
        void run(int x) {
            while(x-->0) {
                cout << x << endl;
            }
        }
};
int main() {
    Base b;

    std::thread t( &Base::run, &b, 10);
    t.join();
    return 0;
}

#### 5 static member function
class Base{
    public:
        static void run(int x) {
            while(x-->0) {
                cout << x << endl;
            }
        }
};
int main() {
    
    std::thread t( &Base::run, 10);
    t.join();
    return 0;
}

- join()  ကို ခေါ်ပြီး thread လုပ်ငန်း ပြီးအောင်စောင့်ရတယ်။ wait  ရတယ်ပေါ့။
- နှစ်ခါ join() ရင် system error နဲ့ terminate ဖြစ်တယ်။
- နှစ်ခါ မ join မိအောင် joinable() ဖြစ်မဖြစ် စစ်သင့်တယ်။ if (t1.joinable()) { t1.join(); blabla; }
- main thread ကနေ အဲ့လို မစောင့်ချင်ရင် detach() လုပ်ပါ။ နှစ်ခါ detach() မဖြစ်အောင် joinable() သုံးပါ။
- 03_...cpp ကိုကြည့်ရင် t1 နဲ့ thread ဖန်တီးပြီး detach လုပ်ထားပါတယ်။ os က child thread ကို ဖန်တီးဖို့ resource နဲ့ အချိန်နဲနဲယူပါတယ်။ အဲ့အချိန်မှာ main thread က လျင်မြန်စွာ ပြီးဆုံးသွားတဲ့အချိန်ထိ child thread က မပြီးသေးတာဖြစ်နိုင်ပါတယ်။ အဲ့အခါကျ os က ဒီ child ဘယ်ကလာလဲဆိုတာသိတာမို့လို့ parent thread မရှိတော့တာနဲ့ child thread ကို suspend လုပ်ပစ်ပါတယ်။ 
- thread object ဖန်တီးပြီးရင် join() သို့မဟုတ် detach() ခေါ်ပေးဖို့လိုပါတယ်။ မခေါ်ထားရင်တော့ thread ရဲ့ destructor က thread ကို joinable ဖြစ်/မဖြစ် စစ်ပါတယ်။ joinable() ဖြစ်ရင် terminate လုပ်ပစ်တာမို့ ကျတော်တို့အတွက် အဆင်မပြေနိုင်ပါ။ ကိုက join() သို့မဟုတ် detach() လုပ်ထားရင်တော့ joinable() မဖြစ်တာမို့ destructor က ဒုက္ခမပေးနိုင်ပါဘူး။