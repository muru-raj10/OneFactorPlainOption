//Test file for Group A functions. 
//Batch 1,2,3,4 are stock options. Let C and P denote calls and puts for each batch. Batch1C is a call option for batch 1
//

#include <cmath>
#include <iostream>
#include <vector>
#include "EuropeanOptions.hpp"
#include "Global.hpp"
#include "OptionData.hpp"
#include "EurCallOption.hpp"
#include "EurPutOption.hpp"

using namespace std;
using namespace global;



int main()
{
	EurCallOption Batch1C;				//Testing Batch 1C, Batch 1 call option

	Batch1C.StockPrice(60.0);			
	Batch1C.Expiry(0.25);
	Batch1C.InterestRate(0.08);
	Batch1C.Volatility(0.3);
	Batch1C.Strike(65.0);
	Batch1C.CostOfCarry(0.08);

	cout<<"Option type: "<<Batch1C.TypeOfOption()<<endl;	//To test and call option type.
	cout<< Batch1C.Price() <<endl;		//Output price of call option
	cout<<Batch1C.ParityPrice()<<endl;	//Output price of call option from put-call parity. To be the same.	
	cout<<"Aribitrage opportunities available: "<<Batch1C.Arbitrage()<<endl;//Check for arbitrage opportunities
	
	cout<<Batch1C.Delta()<<endl;
	cout<<Batch1C.OptionGamma()<<endl;

	double h1;			//small increment h. Taking h=0.1 would be good

	cout<< "Enter Increment Size: "<<endl;
	cin>> h1 ;

	cout<<Batch1C.DeltaApprox(h1)<<endl;		//Value is close to Delta() function
	cout<<Batch1C.OptionGammaApprox(h1)<<endl;	//Value is close to Gamma() function

	/////////////////////////////////////////////////////////////////////////////////////////////

	EurPutOption Batch1P;				//Testing Batch 1P

	Batch1P.StockPrice(100.0);
	Batch1P.Expiry(1.5);
	Batch1P.InterestRate(0.04);
	Batch1P.Volatility(0.4);
	Batch1P.Strike(120.0);
	Batch1P.CostOfCarry(0);

	cout<< Batch1P.Price() <<endl;
	cout<< Batch1P.ParityPrice()<<endl;
	cout<<"Aribitrage opportunities available: "<<Batch1P.Arbitrage()<<endl;

	
	cout<<Batch1P.Delta()<<endl;
	cout<<Batch1P.OptionGamma()<<endl;

	double h2;			//small increment h. Taking h=0.1 would be good

	cout<< "Enter Increment Size: "<<endl;
	cin>> h2 ;

	cout<<Batch1P.DeltaApprox(h2)<<endl;		//Value is close to Delta() function
	cout<<Batch1P.OptionGammaApprox(h2)<<endl;	//Value is close to Gamma() function

	///////////////////////////////////////////////////////////////////////////////////

	EurCallOption Batch2C;				//Testing Batch 2C

	Batch2C.StockPrice(100.0);
	Batch2C.Expiry(1);
	Batch2C.InterestRate(0.0);
	Batch2C.Volatility(0.2);
	Batch2C.Strike(100.0);
	Batch2C.CostOfCarry(0.0);

	cout<< Batch2C.Price() <<endl;
	cout<< Batch2C.ParityPrice()<<endl;
	cout<<"Aribitrage opportunities available: "<<Batch2C.Arbitrage()<<endl;

	EurPutOption Batch2P;				//Testing Batch 2P

	Batch2P.StockPrice(100.0);
	Batch2P.Expiry(1);
	Batch2P.InterestRate(0.0);
	Batch2P.Volatility(0.2);
	Batch2P.Strike(100.0);
	Batch2P.CostOfCarry(0.0);

	cout<< Batch2P.Price() <<endl;
	cout<< Batch2P.ParityPrice()<<endl;
	cout<<"Aribitrage opportunities available: "<<Batch2P.Arbitrage()<<endl;

	EurCallOption Batch3C;				//Testing Batch 3C

	Batch3C.StockPrice(5.0);
	Batch3C.Expiry(1);
	Batch3C.InterestRate(0.12);
	Batch3C.Volatility(0.5);
	Batch3C.Strike(10.0);
	Batch3C.CostOfCarry(0.12);

	cout<< Batch3C.Price() <<endl;
	cout<< Batch3C.ParityPrice()<<endl;
	cout<<"Aribitrage opportunities available: "<<Batch3C.Arbitrage()<<endl;

	EurPutOption Batch3P;				//Testing Batch 3P

	Batch3P.StockPrice(5.0);
	Batch3P.Expiry(1);
	Batch3P.InterestRate(0.12);
	Batch3P.Volatility(0.5);
	Batch3P.Strike(10.0);
	Batch3P.CostOfCarry(0.12);

	cout<< Batch3P.Price() <<endl;
	cout<< Batch3P.ParityPrice()<<endl;
	cout<<"Aribitrage opportunities available: "<<Batch3P.Arbitrage()<<endl;

	EurCallOption  Batch4C;				//Testing Batch 4C

	Batch4C.StockPrice(100.0);
	Batch4C.Expiry(30.0);
	Batch4C.InterestRate(0.08);
	Batch4C.Volatility(0.3);
	Batch4C.Strike(100.0);
	Batch4C.CostOfCarry(0.08);

	cout<< Batch4C.Price() <<endl;
	cout<< Batch4C.ParityPrice()<<endl;
	cout<<"Aribitrage opportunities available: "<<Batch4C.Arbitrage()<<endl;

	EurPutOption Batch4P;				//Testing Batch 4P

	Batch4P.StockPrice(100.0);
	Batch4P.Expiry(30.0);
	Batch4P.InterestRate(0.08);
	Batch4P.Volatility(0.3);
	Batch4P.Strike(100.0);
	Batch4P.CostOfCarry(0.08);

	cout<< Batch4P.Price() <<endl;
	cout<< Batch4P.ParityPrice()<<endl;
	cout<<"Aribitrage opportunities available: "<<Batch4P.Arbitrage()<<endl;
	/////////////////////////////////////////////////////////////////////////////////////
	//Using Struct to encapsulate option data
	struct OptionData DataBatch1={0.08, 0.3, 65.0, 0.25,0.08};
	EurCallOption B1C;
	EurPutOption B1P;
	cout<<"Call option price: "<< B1C.Price(DataBatch1, 60.0)<<endl;	
	cout<<"Put option price: "<< B1P.Price(DataBatch1, 60.0)<<endl;	

	struct OptionData DataBatch2={0.0, 0.2, 100.0, 1.0,0.0};
	EurCallOption B2C;
	EurPutOption B2P;
	cout<<"Call option price: "<< B2C.Price(DataBatch2, 100.0)<<endl;
	cout<<"Put option price: "<< B2P.Price(DataBatch2, 100.0)<<endl;

	struct OptionData DataBatch3={0.12, 0.5, 10.0, 1.0,0.12};
	EurCallOption B3C;
	EurPutOption B3P;
	cout<<"Call option price: "<< B3C.Price(DataBatch3, 5.0)<<endl;
	cout<<"Put option price: "<< B3P.Price(DataBatch3, 5.0)<<endl;

	struct OptionData DataBatch4={0.08, 0.3, 100.0, 30.0,0.08};
	EurCallOption B4C;
	EurPutOption B4P;
	cout<<"Call option price: "<< B4C.Price(DataBatch4, 100.0)<<endl;
	cout<<"Put option price: "<< B4P.Price(DataBatch4, 100.0)<<endl;

	/////////////////////////////////////////////////////////////////////////////////////////
	//Mesh size for underlying Stock price. Let the _S indicate it is a mesh for stock price
	double h_S=0;
	double Start_S=0;
	double End_S=0;
	 
	cout<< "Enter Starting value for underlying stock price S: "<<endl;
	cin>> Start_S;

	cout<< "Enter Mesh Size: "<<endl;
	cin>> h_S ;							

	cout<< "Enter Ending value for S: "<<endl;
	cin>> End_S;

	vector<double> mesh_S = MeshArray(Start_S,h_S,End_S);
	cout<<"Your mesh for S"<<endl;
	print(mesh_S);

	//Option prices at each mesh point of underlying Stock price S for Batch 1. Call and Put
	vector<double> OptionPrice_B1C_S;	//Option price of Batch 1 call, under mesh of stock prices

	for (int i= 0; i< mesh_S.size(); ++i)
	{
		OptionPrice_B1C_S.push_back(B1C.Price(DataBatch1,mesh_S[i])); 
	}
	cout<<"Call Option prices for Batch 1 along mesh points of S"<<endl;
	print(OptionPrice_B1C_S);

	vector<double> OptionPrice_B1P_S;	//option price of Batch 1 put, under mesh of stock prices

	for (int i= 0; i< mesh_S.size(); ++i)
	{
		OptionPrice_B1P_S.push_back(B1P.Price(DataBatch1,mesh_S[i])); 
	}
	cout<<"Put Option prices for Batch 1 along mesh points of S"<<endl;
	print(OptionPrice_B1P_S);
	///////////////////////////////////////////////////////////////////////////////////////
	//Mesh points for different expiry dates, T. Let _T indicate it is a mesh for Expiry time T
	double h_T=0;
	double Start_T=0;
	double End_T=0;
	 
	cout<< "Enter Starting value for Expiry T: "<<endl;
	cin>> Start_T;

	cout<< "Enter Mesh Size: "<<endl;
	cin>> h_T ; 

	cout<< "Enter Ending value for T: "<<endl;
	cin>> End_T;

	vector<double> mesh_T = MeshArray(Start_T,h_T,End_T);
	cout<<"Your mesh for T"<<endl;
	print(mesh_T);

	//Option prices at each mesh point of Expiry T for Batch 1 call and put. Using global functions
	vector<double> OptionPrice_B1C_T;	//option price of Batch 1 call under mesh of T

	for (int i= 0; i< mesh_T.size(); ++i)
	{
		OptionPrice_B1C_T.push_back(CallPrice(60,0.08,0.3,65,mesh_T[i],0.08)); 
	}
	cout<<"Call Option prices for Batch 1 along mesh points of T"<<endl;
	print(OptionPrice_B1C_T);

	vector<double> OptionPrice_B1P_T;//option price of batch 1 put under mesh of T

	for (int i= 0; i< mesh_T.size(); ++i)
	{
		OptionPrice_B1P_T.push_back(PutPrice(60,0.08,0.3,65,mesh_T[i],0.08)); 
	}
	cout<<"Put Option prices for Batch 1 along mesh points of T"<<endl;
	print(OptionPrice_B1P_T);

	////////////////////////////////////////////////////////////////////////////////////
	//Mesh points for different sigma, sig. Let _sig denote the mesh for volaitlity
	double h_sig=0;
	double Start_sig=0;
	double End_sig=0;
	 
	cout<< "Enter Starting value for volatility sigma: "<<endl;
	cin>> Start_sig;

	cout<< "Enter Mesh Size: "<<endl;
	cin>> h_sig ; 

	cout<< "Enter Ending value for sigma: "<<endl;
	cin>> End_sig;

	vector<double> mesh_sig = MeshArray(Start_sig,h_sig,End_sig);
	cout<<"Your mesh for sigma"<<endl;
	print(mesh_sig);

	//Option prices at each mesh point of sigma for Batch 1. Call and put
	vector<double> OptionPrice_B1C_sig;	//option price of batch 1 call under mesh of sigma

	for (int i= 0; i< mesh_sig.size(); ++i)
	{
		OptionPrice_B1C_sig.push_back(CallPrice(60,0.08,mesh_sig[i],65,0.25,0.08)); 
	}
	cout<<"Call Option prices for Batch 1 along mesh points of sig"<<endl;
	print(OptionPrice_B1C_sig);

	vector<double> OptionPrice_B1P_sig;	//option price of batch 1 put under mesh of sigma

	for (int i= 0; i< mesh_sig.size(); ++i)
	{
		OptionPrice_B1P_sig.push_back(PutPrice(60,0.08,mesh_sig[i],65,0.25,0.08)); 
	}
	cout<<"Put Option prices for Batch 1 along mesh points of sig"<<endl;
	print(OptionPrice_B1P_sig);
	////////////////////////////////////////////////////////////////////////////////////////////

	EurCallOption FuturesCall1;			//Create Futures call option. DIfferent value for b.

	FuturesCall1.StockPrice(105.0);
	FuturesCall1.Expiry(0.5);
	FuturesCall1.InterestRate(0.1);
	FuturesCall1.Volatility(0.36);
	FuturesCall1.Strike(100.0);
	FuturesCall1.CostOfCarry(0.0);		//b=0 here.
	
	cout<<"For Futures option"<<endl;
	cout<<FuturesCall1.Price()<<endl;
	cout<<FuturesCall1.Delta()<<endl;
	cout<<FuturesCall1.OptionGamma()<<endl;

	EurPutOption FuturesPut1;			//Create futures put option
	
	FuturesPut1.StockPrice(105.0);
	FuturesPut1.Expiry(0.5);
	FuturesPut1.InterestRate(0.1);
	FuturesPut1.Volatility(0.36);
	FuturesPut1.Strike(100.0);
	FuturesPut1.CostOfCarry(0.0);

	cout<<FuturesPut1.Price()<<endl;
	cout<<FuturesPut1.Delta()<<endl;
	cout<<FuturesPut1.OptionGamma()<<endl;
/////////////////////////////////////////////////////////////////////////////////////////
	//Mesh points for different Stock price, S, _S2 will denote the second mesh array of Stock price
	double h_S2=0;
	double Start_S2=0;
	double End_S2=0;
	 
	cout<< "Enter Starting value for underlying S: "<<endl;
	cin>> Start_S2;

	cout<< "Enter Mesh Size: "<<endl;
	cin>> h_S2 ; 

	cout<< "Enter Ending value for S: "<<endl;
	cin>> End_S2;

	vector<double> mesh_S2 = MeshArray(Start_S2,h_S2,End_S2);
	cout<<"Your mesh for S"<<endl;
	print(mesh_S2);

	//Option Deltas at each mesh point of Stock prices for Batch 1. Call.
	vector<double> OptionDelta_FC_S2;	//option deltas of futures call option under mesh2 of stock prices 

	for (int i= 0; i< mesh_S2.size(); ++i)
	{
		OptionDelta_FC_S2.push_back(CallDelta(mesh_S2[i],0.1,0.36,100,0.5,0.0)); 
	}

	cout<<"Futures Call Option Delta along mesh points of S"<<endl;
	print(OptionDelta_FC_S2);

	vector<double> OptionPrice_FC_S2;				//Option prices for futures call option under mesh2 of stock prices

	for (int i= 0; i< mesh_S2.size(); ++i)
	{
		OptionPrice_FC_S2.push_back(CallPrice(mesh_S2[i],0.1,0.36,100,0.5,0.0)); 
	}

	cout<<"Futures Call Option Price along mesh points of S"<<endl;
	print(OptionPrice_FC_S2);
	/////////////////////////////////////////////////////////////////////////////////

	double h;			//small increment h. Taking h=0.1 would be good

	cout<< "Enter Increment Size: "<<endl;
	cin>> h ;

	cout<<FuturesCall1.DeltaApprox(h)<<endl;		//Value is close to Delta() function
	cout<<FuturesCall1.OptionGammaApprox(h)<<endl;	//Value is close to Gamma() function

	cout<<FuturesPut1.DeltaApprox(h)<<endl;
	cout<<FuturesPut1.OptionGammaApprox(h)<<endl;
}