import java.util.Scanner;

public class QuizWithTimer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[][] quiz = {
                {"What is the capital of France?", "Paris"},
                {"What is 2 + 2?", "4"},
                {"Name the largest planet in our solar system.", "Jupiter"}
        };

        for (String[] question : quiz) {
            System.out.println(question[0]);

            long startTime = System.currentTimeMillis(); // Timer start
            String userAnswer = scanner.nextLine();
            long endTime = System.currentTimeMillis(); // Timer end

            long reactionTime = endTime - startTime;
            System.out.println("Your reaction time: " + reactionTime + " milliseconds");

            if (userAnswer.equalsIgnoreCase(question[1])) {
                System.out.println("Correct!");
            } else {
                System.out.println("Incorrect! The correct answer is " + question[1]);
            }
        }

        scanner.close();
    }
}
