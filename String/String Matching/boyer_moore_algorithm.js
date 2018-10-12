export const search = (string, pattern) => {
    const mainString = string.split('');
    pattern = pattern.split('');
    let i = 0, j;
    while (i < mainString.length) {
        for (j = pattern.length - 1; j >= 0; j--) {
            if (i + j >= mainString.length) return null;
            if (mainString[i + j] !== pattern[j]) break;
        }
        if (j > 0) {
            let k = j;
            do {
                k--;
            } while (k > 0 && mainString[i + j] !== pattern[k]);
            i += j - k;
        }
        else {
            return i;
        }
    }
};
