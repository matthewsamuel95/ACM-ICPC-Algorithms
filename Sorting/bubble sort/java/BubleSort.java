/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Scanner;
 
/**
 * 
 * @author Yudi Setiawan
 * 
 * Bubble Sort
 *
 */
 
public class BubleSort
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
         
        System.out.print("Input data n : ");    int n_data = s.nextInt();
        
        int[] data = new int[n_data];       
        System.out.println();
        for(int a = 0; a < n_data; a++)
        {
            System.out.print("Data -"+(a+1)+" : ");
            data[a] = s.nextInt();
        }
        
        System.out.println("\nData before sorted");
        for(int a = 0; a < n_data; a++)
            System.out.print(data[a]+" ");
         
        //    Proses Bubble Sort
        System.out.println("\nProcces Bubble Sort");
        for(int a = 0; a < n_data; a++)
        {
            System.out.println("Iterasi -"+(a+1)+" :");
            for(int b = 0; b < n_data; b++)
                System.out.print(data[b]+"  ");
             
            System.out.println("   Compare "+data[0]+" with "+data[1]);
            for(int b = 0; b < n_data-1; b++)
            {
                String Message = "   There is no sorting";
                if(data[b] > data[b+1])
                {
                    Message = "   Data "+data[b]+" switch with "+data[b+1];
                    int temp = data[b];        
                    data[b] = data[b+1];    
                    data[b+1] = temp;
                     
                }
             
                if(b < n_data-(a+1))
                {
                    for(int c = 0; c < n_data; c++)
                        System.out.print(data[c]+"  ");
                     
                    System.out.println(Message);;
                }
            }
 
            System.out.println("\n");
        }
         
        System.out.print("Data after Sorted : ");
        for(int a = 0; a < n_data; a++)
            System.out.print(data[a]+"  ");
         
    }
}