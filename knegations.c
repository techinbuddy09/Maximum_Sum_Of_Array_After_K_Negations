// basically in this ques we are using the greedy approach and then proceeding further
//according to the provided ques firstly sort the given array in order to get all min -ve no
// then make all the -ve numbers to positve uptill k times 
//if k is still left and we have reached a +ve no then break it ..no need to do changes because it will make sum -ve 
// so after this sort the array again and then no at 0th index change it if odd then make it negative else +ve

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();
        int max_sum=0;
        sort(nums.begin(),nums.end());//firstly sort the array
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0 && k>0) // will make number negative till number is negative and k zero
            {
                nums[i]=-nums[i];
                k--;//decrease the value of k too
            }
            else
            {
                break;// foe positive numbers dont modify
            }
        }
        // now after this position sort the array again
        sort(nums.begin(),nums.end());// for getting the max number 
        // for the left k operations if
        if(k%2!=0) // if its odd
        {
            // then modify min number to negative
            nums[0]=-nums[0];//min number at the 0th index
        }
        //now calculating the maximum sum of the array after k negations
        for(int i=0;i<n;i++)
        {
            max_sum=max_sum+nums[i];
        }
        return max_sum;// return the final max sum
    }

};
