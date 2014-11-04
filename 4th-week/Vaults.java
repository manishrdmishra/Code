import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

class Fraction {

	Fraction() {
		// int a = 0;
		numerator = BigInteger.valueOf(0);
		denominator = BigInteger.valueOf(1);
	}

	Fraction(BigInteger a, BigInteger b) {

		numerator = a;
		denominator = b;
	}

	Fraction add(Fraction x) {
		Fraction y = new Fraction();
		if (denominator == x.denominator) {
			y.numerator = numerator.add(x.numerator);
			y.denominator = denominator;
		} else {
			y.numerator = numerator.multiply(x.denominator).add(
					(x.numerator.multiply(denominator)));
			y.denominator = denominator.multiply(x.denominator);
		}
		y.dividByGcd();
		return y;
	}

	void dividByGcd() {
		BigInteger bi = numerator.gcd(denominator);
		numerator = numerator.divide(bi);
		denominator = denominator.divide(bi);

	}

	// std::ostream& operator<<(std::ostream& out);
	BigInteger numerator;
	BigInteger denominator;

}

class Dice {
	String dice_desc;
	// ArrayList diceNums = new ArrayList() ;
	ArrayList diceFaces = new ArrayList();

	Dice(String dice) {
		dice_desc = dice;

	}

	int charToInt(char num[] ,int count)
	{
		int n=0;
		if(count == 1)
		{
			n = num[0] - '0';
			
		}
		else if(count ==2)
		{
			
			n= (num[0] - '0')*10 + (num[1] - '0');
		}
		return n;
			
	}
	void parseDice() {
		//String[] dices = dice_desc.split("+|"\n");
		//System.out.println(dice_desc);

		int count=0;
		int n=0;
		int i=0;
		int faces;
		while( i < dice_desc.length())
		{
			char[] num = new char[3];
			//num[count] = dice_desc.charAt(i);
			count = 0;
			while(i <dice_desc.length() && dice_desc.charAt(i)!= 'd')
			{
				
			num[count++] = dice_desc.charAt(i++) ;
			//System.out.println(num[count - 1]);
				//ount++;
			}
			n = charToInt(num,count);
			//num[count] ='\0';
			//System.out.println(num);
		//	n = Integer.parseInt(new String(num));
			
			
			i++;
			
			count =0;
			while(i<dice_desc.length() && dice_desc.charAt(i)!= '+')
			{
				
			num[count++] = dice_desc.charAt(i++) ;
				//ount++;
			}
			i++;
			faces = charToInt(num,count);
			
			
			/*System.out.println("number of dices: " + n);
			System.out.println("number of sides: " + faces);*/
			for (int j = 0; j < n; j++) {
				// diceNums.add(Integer.getInteger(oneDice[0]));
				diceFaces.add(faces);
			}
		}

	}

	Fraction find_probability(int n) {
		Fraction[][] p = new Fraction[54][1005];
		// int sides = 20;

		// p[1][0] = Fraction(BigInteger,1);
		int sides = (int) diceFaces.get(0);
		p[1][0] = new Fraction(BigInteger.valueOf(1),
				BigInteger.valueOf(1));
		for (int j = 1; j <= n; j++) {
			if (sides < j) {
				p[1][j] = new Fraction(BigInteger.valueOf(0),
						BigInteger.valueOf(1));
			} else {
				p[1][j] = new Fraction(BigInteger.valueOf(sides - j + 1),
						BigInteger.valueOf(sides));
			}
			//System.out.println(p[1][j].numerator + "/" + p[1][j].denominator);
		}
		
		for (int i = 2; i <= diceFaces.size(); i++) {
			// p[i][0] = 0;
			
			//System.out.println("*************");
			p[i][0] = new Fraction(BigInteger.valueOf(1),
					BigInteger.valueOf(1));
			for (int j = 1; j <= n; j++) {
				sides = (int) diceFaces.get(i -1);
				Fraction x = new Fraction();
				for (int k = 1; k <= sides; k++) {
					if (k > j) {
						/*p[i - 1][j - k] = new Fraction(BigInteger.valueOf(1),
								BigInteger.valueOf(1));*/

						
						 x = x.add(new Fraction(BigInteger.valueOf(1),
						 BigInteger.valueOf(1 * sides)));
						 
					} 
					else {
						x = x.add(new Fraction(p[i - 1][j - k].numerator,
								p[i - 1][j - k].denominator.multiply(BigInteger
										.valueOf(sides))));
					}
					x.dividByGcd();
					/*System.out.println(x.numerator + "/"
							+ x.denominator);*/
				}

				p[i][j] = x;
				p[i][j].numerator.gcd(p[i][j].denominator);
				/*System.out.println(p[i][j].numerator + "/"
						+ p[i][j].denominator);*/
			}

		}
		p[diceFaces.size()][n].dividByGcd();
		if(p[diceFaces.size() ][n].numerator == BigInteger.valueOf(0))
		{
			p[diceFaces.size()][n].numerator = BigInteger.valueOf(0);
			p[diceFaces.size() ][n].denominator = BigInteger.valueOf(1);
			
			
		}
		
	/*	System.out.println("******************");
		for(int i =1 ; i<= diceFaces.size();i++)
		{
			
			for(int j =0 ; j<=n;j++)
			{
				System.out.print(p[i][j].numerator + "/"
						+ p[i][j].denominator + "   ");
				
			}
			System.out.println();
		}*/
		return p[diceFaces.size() ][n];
	}

}

public class Vaults {
	public static void main(String arg[]) {
		int t;
		Scanner in = new Scanner(System.in);
		t = in.nextInt();
		ArrayList<Fraction> p= new ArrayList<Fraction>(30);
		for (int i = 1; i <= t; i++) {
			int n;
			String dice;
			n = in.nextInt();
		
			dice = in.nextLine();
			/*if(n==0)
			{
				p.add(new Fraction());
				continue;
				
			}*/
			Dice d = new Dice(dice.substring(1));
			d.parseDice();
			 p.add(d.find_probability(n));
			

		}
		for(int i = 1; i <= t; i++)
		{
			
			System.out.println("Case #"+i+": "+p.get(i-1).numerator+"/"+p.get(i -1).denominator);
		}
		in.close();
		//System.out.println("hello");
	}

}
