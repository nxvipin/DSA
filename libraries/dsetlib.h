/*
* Array based Disjoint set for integers.
* @author: Vipin Nair <swvist@gmail.com>
* @copyright (c) 2011 Vipin Nair
* @license http://www.gnu.org/licenses/gpl.html GNU General Public License V3
*/

class dset{
	private:
		int *DSET;
		int size;
		int rank(int);
	public:
		dset(int);
		~dset();
		void makeSet(int);
		int findSet(int);
		void unionSet(int,int);
		void displaySet();
};
