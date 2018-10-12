
  var str1;
  var str2;
  
  
  str1 = "Aricadu";
  str2 = "Dracula";
  
  isAnagram(str1,str2);
  

function isAnagram(str1,str2){


  if(str1.length == str2.length){
    var A[26];
    var B[26];
    for(var i=0 ;i<str1.length;i++){
        A[parseInt(str1.charAt(i)) - parseInt('a')]++;
        B[parseInt(str2.charAt(i)) - parseInt('a')]++;
        
    }
    var flag = true;
    
    for(i=0 ;i<26){
      if(A[i] != B[i])
        flag = false;
    }
    
    if(!flag)
      console.log("Not an anagram");
    else
      console.log("An anagram")
      
  }else
    console.log("Not an anagram");
    
  

}
