int main() {
    int key = 0;
    int array[N];

    std::ofstream out;
    out.open("hth.csv");
    out << "N,A" << std::endl;
    
    
    for(unsigned counter = 100; counter < N; counter += 5000) {
        randomize(array, counter);
        unsigned seed2 = counter*7;
        std::default_random_engine rng(seed2);
        std::uniform_int_distribution<unsigned> dstr2(0, counter+1);  
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 10000; cnt != 0 ; --cnt) {
            key = dstr2(rng);
            strategy_A(array, counter, key);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span_A_r = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); 
        

        if (out.is_open()) {
            out << counter << ',' << (float) time_span_A_r.count()/10000 << std::endl;
        }
    }
    out.close();
    return 0;
}


int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sorting(a);
    for (int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}