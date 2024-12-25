template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	/** Sets the value at index ind to val. */
	void set(int ind, T val) { add(ind, val - arr[ind]); }

	/** Adds val to the element at index ind. */
	void add(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	/** @return The sum of all values in [0, ind]. */
	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}

	T query(int l, int r) {
		return (pref_sum(r) - pref_sum(l));
	}
};



// Notable uses below:
// Init:         BIT<type> bit_name(bit_size);
// Set:                    bit_name.set(pos, val);
// Add:                    bit_name.add(pos, val);
// Query:                  bit_name.query(l, r);
