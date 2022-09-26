//Problem:  Fractional Knapsack
//-------------------------------------------------------------------------------------
//Code :  Sort Using custom Comparator

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
	double fractionalKnapsack(int W, Item arr[], int n)
	{
		sort(arr, arr+n, [](Item a, Item b){
			double x=(double)a.value/(double)a.weight;
			double y=(double)b.value/(double)b.weight;
			return x>y;
		});
		double maxval=0.0;
		int i=0;
		while(i<n){
			if(arr[i].weight<=W){
				W-=arr[i].weight;
				maxval+=arr[i].value;
			}
			else{
				maxval+= arr[i].value* ((double)W / (double)arr[i].weight);
				break;
			}
			i++;
		}
		return maxval;
	}

};


//Time Complexity:  O(NlogN + N)
//Auxilary Space Complexity:  O(1)
//-------------------------------------------------------------------------------------
