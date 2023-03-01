int bin_search (int (&array)[N], int l, int r, int a) {
    int it = (l + r) / 2;
    if (array[l] + array[l + 1] == a && array[l] != array[l + 1]) {
        return array[l], array[l + 1];
    } 
    else if (array[r] + array[r - 1] == a && array[r] != array[r - 1]) {
        return array[r], array[r - 1];
    } 
    else if (array[l + 1] == array[r]){
        return -1;
    } 
    else if (array[r] + array[r - 1] < a) {
        return -1;
    }
    else if (array[l] + array[l +1] > a) {
        return -1;
    } 
    else if (2 * array[it] < a) {
        return bin_search(array, it, r, a);
    } 
    else if (2 * array[it] > a) {
        return  bin_search(array, l, it, a);
    }
}