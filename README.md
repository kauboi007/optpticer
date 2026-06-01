# optpricer the Options Pricer

A command line options pricing tool built in C++ that computes theoretical prices and greeks for European call and put options using both Black Scholes and Monte Carlo simulation.

## What it does

Takes five market inputs : stock price, strike price, time to expiry, volatility, and risk free rate  and outputs Black Scholes price, Monte Carlo simulated price, and Delta for both calls and puts. Also generates a convergence CSV showing how the MC estimate stabilizes as path count increases.

## Build and Run

g++ main.cpp bs_pricer.cpp mc_pricer.cpp greeks.cpp utils.cpp -o pricer
./pricer

## Visualize MC Convergence

python3 plot.py

## Verified Against

S=100, K=100, T=1, sigma=0.2, r=0.05 produces BS Call 10.4506, BS Put 5.5735, Call Delta 0.6368.

## Future Scope

- Additional greeks: Gamma, Vega, Theta, Rho
- Implied volatility solver given a market price
- Multi-step path simulation for American options with early exercise
- Term structure and volatility surface support
- Portfolio-level pricing across multiple positions

## Built With

C++17, Python 3, matplotlib

#Built by Kaushik(Kauboi) <3
