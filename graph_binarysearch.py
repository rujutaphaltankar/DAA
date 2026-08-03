import matplotlib.pyplot as plt

# Data from Table A
input_sizes = [100, 500, 1000, 5000, 10000, 50000]
binary_search_cmps = [7, 9, 10, 13, 14, 16]
linear_search_cmps = [100, 500, 1000, 5000, 10000, 50000]

# Create Figure
plt.figure(figsize=(9, 6), dpi=300)

# Plot Linear and Binary Search curves
plt.plot(input_sizes, linear_search_cmps, marker='o', color='red', linewidth=2, label='Linear Search O(n)')
plt.plot(input_sizes, binary_search_cmps, marker='s', color='blue', linewidth=2, label='Binary Search O(log n)')

# Configure Logarithmic Scale on X-axis as required by guidelines
plt.xscale('log')

# Formatting Labels & Title
plt.xlabel('Input Size (n) [Logarithmic Scale]', fontsize=12, fontweight='bold')
plt.ylabel('Number of Comparisons', fontsize=12, fontweight='bold')
plt.title('Comparison Count: Binary Search vs Linear Search', fontsize=14, fontweight='bold', pad=15)

# Annotate key data points on Binary Search curve
for i, txt in enumerate(binary_search_cmps):
    plt.annotate(f"{txt}", (input_sizes[i], binary_search_cmps[i]), textcoords="offset points", xytext=(0,10), ha='center', fontsize=9, color='blue', weight='bold')

# Styling Grid & Legend
plt.grid(True, which="both", ls="--", alpha=0.5)
plt.legend(fontsize=11, loc='upper left')

# Tight Layout and Save Output Image
plt.tight_layout()
plt.savefig('Binary_vs_Linear_Search_Graph.png')
plt.show()