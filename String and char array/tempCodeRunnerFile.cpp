  count2[s2[i] - 'a']++;
        count2[s2[i-size] - 'a']--;
        if(check(count1,count2))
            return true;