import java.util.*;
public class Student_grade_calculation {
    public static void main(String[] args) {
        int total=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your total number of Subjects :");
        int n=sc.nextInt();
         int []marks=new int[n];
         for(int i=0;i<n;i++){
            System.out.println("Enter Your "+(i+1)+"th Subject Obtained  marks :");
            marks[i]=sc.nextInt();
            total+=marks[i];
         }
        System.out.println("total :"+total);
        int avg=total/n;
        float percentage=(float)(total*100)/(n*100f);
        float p=percentage;
        System.out.println("Average marks is :"+avg);
        System.out.println("Total percentage is  "+percentage);
        if(p>90){
          System.out.println("YOur Grade is A");
        }
        else if (p>80){
                 System.out.println("Your Grade is B");
              }
        else if (p>70) {
                System.out.println("Your Grade is C");
        }
        else if (p>60) {
            System.out.println("Your Grade is D");
        }                     
        else if (p>50 &&p<60) {
        System.out.println("Your Grade is E");
        } 
        else{
            System.out.println("\tYour Grade is not Specified ..\n \tYou Have to Improve yourself \n \t Better luck next Time");
        }                     

    }
}
