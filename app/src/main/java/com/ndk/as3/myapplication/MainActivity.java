package com.ndk.as3.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    String TAG = "MainActivity";
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("inshow-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(sayHelloWorld());

        int[] args = new int[]{1, 3, 4, 5, 9};
        for (int i = 0; i < args.length; i++) {
            Log.d(TAG, "testData: before " + args[i]);
        }
        operateArrary(args);

        for (int i = 0; i < args.length; i++) {
            Log.d(TAG, "testData: after " + args[i]);
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
//    public native String stringFromJNI();
    public native String sayHelloWorld();

    public native void operateArrary(int[] args);
}
