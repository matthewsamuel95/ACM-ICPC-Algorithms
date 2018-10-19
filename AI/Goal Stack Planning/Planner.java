import java.util.*;

import javax.lang.model.util.ElementScanner6;

class Planner
{
int k;

int[][] on;
int[] ontable;
int[] clear;
char holding;
int armempty;
char[] alphabet;

String start;
String goal;


Scanner sc = new Scanner(System.in);
	
	Stack<String> goalstack = new Stack<>();
	ArrayList<String> actions = new ArrayList<>();
	Planner(int n)
	{
		k=n;
		on = new int[n][n];
		ontable = new int[n];
		clear = new int[n];
		armempty = 1;	
		alphabet = "abcdefghijklmnopqrstuvwxyz".toCharArray();

	}
	public void input()
	{

		System.out.println("Enter Start State");
		start = sc.next();
		System.out.println("Enter Goal State");
		goal = sc.next();
		// start = "ontable(a)^ontable(c)^on(b,a)^clear(b)^clear(c)^armempty";
		// goal = "clear(a)^ontable(c)^on(a,b)^on(b,c)^armempty";

		//start = "ontable(b)^ontable(c)^on(d,b)^on(a,c)^clear(d)^clear(a)^armempty";	
		//goal =  "ontable(a)^on(b,a)^on(c,b)^on(d,c)^clear(d)^armempty";	
	};
		
	public void set_initial()
	{
		String sg[] = start.split("['^']");
		for(int i=0;i<sg.length;i++)
		{	
			if(sg[i].contains("ontable"))
			{
				ontable[sg[i].charAt(8)%97] = 1;
			}
			else if(sg[i].contains("on"))
			{
				on[sg[i].charAt(3)%97][sg[i].charAt(5)%97] = 1;
			}
			else if(sg[i].contains("clear"))
			{
				clear[sg[i].charAt(6)%97] = 1;
			}
			else if(sg[i].contains("holding"))
			{
				holding = sg[i].charAt(8);
			}
			else if(sg[i].contains("armempty"))
			{
				armempty = 1;
			}
			
		}


	}	
	
	public boolean check(String state)
	{	
		if(state.contains("^"))
		{
			//System.out.println();
			//System.out.println(state);	
			String simple_state[] = state.split("['^']");
			
			for(int i=0;i<simple_state.length;i++)
			{
				
				//System.out.println(simple_state[i]);
				if(!check_simple(simple_state[i]))
				{
					return false;
				} 	
			}
			
			return true;
			
		}
		else
		{
			return check_simple(state);
		}
	}	
	
	public boolean check_simple(String state)
	{
			if(state.contains("ontable") && ontable[state.charAt(8)%97] == 1)
			{
				return true;
			}
			else if(state.contains("on(") && on[state.charAt(3)%97][state.charAt(5)%97] == 1)
			{
				return true;
			}
			else if(state.contains("clear") && clear[state.charAt(6)%97] == 1)
			{
				return true;
			}
			else if(state.contains("holding") && holding==state.charAt(8))
			{
				return true;
			}
			else if(state.contains("armempty") && armempty == 1)
			{
				return true;
			}
			else
			{
				return false;
			}			
	}
	
	public void preAction(String action)
	{
		
		if(action.contains("ontable"))
			{
				goalstack.push("putdown("+action.charAt(8)+")");
				
				//preconditions
				goalstack.push("holding("+action.charAt(8)+")");
			}
			else if(action.contains("on"))
			{
				goalstack.push("stack("+action.charAt(3)+","+action.charAt(5)+")");
				
				//preconditions
				goalstack.push("clear("+action.charAt(5)+")^"+"holding("+action.charAt(3)+")");
				//goalstack.push("holding("+action.charAt(3)+")");

			}
			else if(action.contains("clear"))
			{
				int i;
				for( i = 0;i<k;i++)
				{
					if(on[i][action.charAt(6)%97]==1)
					{
						break;
					}
				}
					
				
				goalstack.push("unstack("+alphabet[i]+","+action.charAt(6)+")");
				
				//preconditions
				goalstack.push("on("+alphabet[i]+","+action.charAt(6)+")^"+"clear("+alphabet[i]+")^armempty");
				//goalstack.push("clear("+alphabet[i]+")");
				//goalstack.push("armempty");

				
			}
			else if(action.contains("holding"))
			{

				if(ontable[action.charAt(8)%97] == 1)
				{
					
					goalstack.push("pickup("+action.charAt(8)+")");
					
					//preconditions
					
					goalstack.push("ontable("+action.charAt(8)+")^"+"clear("+action.charAt(8)+")^armempty");
					//goalstack.push("armempty");
				}
				else
				{
					int i;
					for( i = 0;i<k;i++)
					{
						if(on[action.charAt(8)%97][i]==1)
						{
							break;
						}
					}
					
					goalstack.push("unstack("+action.charAt(8)+","+alphabet[i]+")");
				
					//preconditions
					goalstack.push("on("+action.charAt(8)+","+alphabet[i]+")^"+"clear("+action.charAt(8)+")^armempty");
					//goalstack.push("clear("+action.charAt(8)+")");
					//goalstack.push("armempty");
				}

			}
			else if(action.contains("armempty"))
			{
				goalstack.push("putdown("+holding+")");
				
				//preconditions
				goalstack.push("holding("+holding+")");
			}

	}

	public void postAction(String action)
	{

			if(action.contains("unstack"))
			{
				//add
				holding = action.charAt(8);
				clear[action.charAt(10)%97] = 1;
				
				//delete
				armempty = 0;
				on[action.charAt(8)%97][action.charAt(10)%97] = 0;

			}
			else if(action.contains("stack"))
			{
				//add
				armempty = 1;
				on[action.charAt(6)%97][action.charAt(8)%97] = 1;
				clear[action.charAt(6)%97] = 1;
				
				//delete
				clear[action.charAt(8)%97] = 0;
				holding= 0;
			}
			else if(action.contains("pickup"))
			{
				//add
				holding = action.charAt(7);
				
				//delete
				armempty = 0;
				ontable[action.charAt(7)%97] = 0;
				
			}
			else if(action.contains("putdown"))
			{
				//add
				armempty = 1;
				ontable[action.charAt(8)%97] = 1;
				
				//delete
				holding = 0;

			}

	}
	
	public void print()
	{
			for(int q=0;q<k;q++)
			{
				System.out.println();
				for(int j=0;j<k;j++)
				{
					System.out.print(on[q][j]+" ");
				}
			}
			
			System.out.println();
			System.out.println();
			for(int j=0;j<k;j++)
			{
				System.out.print(ontable[j]+" ");
			}
	}

	public void plan()
	{
		goalstack.push(goal);
		// String sg[] = start.split("['^']");
		String current;

		while(!goalstack.isEmpty())
		{
			//System.out.println();
			//print();
			//System.out.println(goalstack.clone());

			current = goalstack.pop();
			//System.out.println(current);
			if(current.contains("stack") || current.contains("unstack")  || current.contains("pickup") || current.contains("putdown") )
			{
				postAction(current);
				actions.add(current);
			}
			else if(!check(current))
			{
				
				if(current.contains("^"))
				{
					goalstack.push(current);
					String sg[] = current.split("['^']");
					for(int i=0;i<sg.length;i++)
					{
						goalstack.push(sg[i]);
					}
				}
				else{
					goalstack.push(current);
					preAction(current);
				}
			}





		}
		
		
	}

	public void dispAction()
	{	
		
		System.out.println("\nActions:");
		for(int i=0;i<actions.size();i++)
		{
			System.out.println(actions.get(i));
		}
	}

	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter no of block");
		int k = s.nextInt();
		Planner p = new Planner(k);
		p.input();
		p.set_initial();
		p.plan();
		p.dispAction();

		s.close();
	}
}
