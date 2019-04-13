#include <bits/stdc++.h>

using namespace std;

int main() {
  	string monster, mech;
  	cin >> monster;

  	for (int i = 0; i < monster.length(); i++){
    	if (monster[i] == 'R' && monster[i+1] == 'B' && monster[i+2] == 'L'){
      		mech = 'C';
      		i += 2;
      		cout << mech;
    	}

    	else if(monster[i] == 'R' && monster[i+1] == 'L' && monster[i+2] == 'B'){
      		mech = 'C';
      		i += 2;
      		cout << mech;
    	}

    	else if(monster[i] == 'L' && monster[i+1] == 'R' && monster[i+2] == 'B'){
      		mech = 'C';
     	 	i += 2;
      		cout << mech;
    	}

    	else if(monster[i] == 'L' && monster[i+1] == 'B' && monster[i+2] == 'R'){
      		mech = 'C';
      		i += 2;
      		cout << mech;
    	}
	
    	else if(monster[i] == 'B' && monster[i+1] == 'L' && monster[i+2] == 'R'){
      		mech = 'C';
      		i += 2;
      		cout << mech;
    	}

    	else if(monster[i] == 'B' && monster[i+1] == 'R' && monster[i+2] == 'L'){
      		mech = 'C';
      		i += 2;
      		cout << mech;
    	}

    	else if(monster[i] == 'R'){
      		mech = 'S';
      		cout << mech;
    	}

    	else if(monster[i] == 'B'){
      		mech = 'K';
      		cout << mech;
    	}

    	else if(monster[i] == 'L'){
      		mech = 'H';
      		cout << mech;
    	}
  	}

  	cout << endl;
}
