 function palindrome(str) {
      str = str.toLowerCase().replace(/[\W_]/g, '');
      for(var i = 0, len = str.length - 1; i < len/2; i++) {
        if(str[i] !== str[len-i]) {
          return false;
        }
      }
      return true;
    }
