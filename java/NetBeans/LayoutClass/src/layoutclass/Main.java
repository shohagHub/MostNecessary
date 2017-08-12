/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package layoutclass;

import java.util.concurrent.Executors;

/**
 *
 * @author shohag
 */
public class Main {

    public static void main(String[] args) {
        Executors.newSingleThreadExecutor().execute(new Runnable() {
            @Override
            public void run() {
                // code in here

            }
        });

        
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
               
                FaceBookFrame frame = new FaceBookFrame();
                frame.launchSignUp();
                frame.setVisible(true);
            }
        });
//        java.awt.EventQueue.invokeLater(new Runnable() {
//            public void run() {
//                new Information().setVisible(true);
//            }
//        });

    }

}
