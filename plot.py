import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("convergence.csv", header=None, names=["paths", "price"])

plt.figure(figsize=(10, 5))
plt.plot(df["paths"], df["price"], color="steelblue", linewidth=0.8)
plt.axhline(y=10.4506, color="red", linestyle="--", linewidth=1, label="BS Price")
plt.title("Monte Carlo Convergence")
plt.xlabel("Number of Paths")
plt.ylabel("Estimated Call Price")
plt.legend()
plt.tight_layout()
plt.savefig("convergence.png", dpi=150)
plt.show()