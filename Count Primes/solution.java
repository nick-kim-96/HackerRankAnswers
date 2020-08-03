class Solution {
    public int countPrimes(int n) {
        List<Boolean> list = new ArrayList<Boolean>();
        
        for(int i = 0; i < n; i++) {
            list.add(true);
        }
        
        for(int i = 2; i * i < list.size(); i++) {
            for(int j = i; i * j < list.size(); j++) {
                list.set(i * j, false);
            }
        }
        
        int count = 0;
        for(int i = 2; i < list.size(); i++){
            if(list.get(i) == true) count++;
        }
        
        return count;
    }
}