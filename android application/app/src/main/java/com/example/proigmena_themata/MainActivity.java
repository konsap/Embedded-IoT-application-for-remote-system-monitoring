package com.example.proigmena_themata;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class MainActivity extends AppCompatActivity {

    //public String mresult = "here";
    //private TextView data;
    private TextView temp_data;
    private TextView light_data;
    private ImageView img;
    Handler myHandler = new Handler();
    Runnable timedTask;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        //Switch Listeners

        Switch led1 = (Switch) findViewById(R.id.led1);
        Switch led2 = (Switch) findViewById(R.id.led2);

        led1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                new HttpRequestLed1().execute();
            }
        });


        led2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                new HttpRequestLed2().execute();
            }
        });



        /* Get data every second */

         timedTask = new Runnable() {
            @Override
            public void run() {

                temp_data = (TextView) findViewById(R.id.temp);
                //light_data = (TextView) findViewById(R.id.light);
                img = (ImageView) findViewById(R.id.img);

                new HttpRequestTemp().execute();
                new HttpRequestLight().execute();

                myHandler.postDelayed(timedTask, 1000);
            }
        };
         myHandler.post(timedTask);


         // Switch Listeners



    }



    public class HttpRequestTemp extends AsyncTask<URL, String, String> {

        @Override
        protected String doInBackground(URL... params) {

            HttpURLConnection connection = null;
            BufferedReader reader = null;

            try {
                URL url = new URL("http://192.168.1.69/temp");
                connection = (HttpURLConnection) url.openConnection();
                connection.connect();

                InputStream stream = connection.getInputStream();

                reader = new BufferedReader(new InputStreamReader(stream));

                StringBuffer buffer = new StringBuffer();

                String value = "";

                while ((value = reader.readLine()) != null) {
                    buffer.append(value);
                    //System.out.println(value);
                }

                return buffer.toString();

            } catch (MalformedURLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (connection != null)
                    connection.disconnect();

                try {
                    if (reader != null)
                        reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return null;
        }

        @Override
        protected void onPostExecute(String result) {
            super.onPostExecute(result);
            if (result != null) {
                temp_data.setText(result);
            }
            else
            {
                temp_data.setText("error");
            }
        }

    }





    public class HttpRequestLight extends AsyncTask<URL, String, String> {

        @Override
        protected String doInBackground(URL... params) {

            HttpURLConnection connection = null;
            BufferedReader reader = null;

            try {
                URL url = new URL("http://192.168.1.69/light");
                connection = (HttpURLConnection) url.openConnection();
                connection.connect();

                InputStream stream = connection.getInputStream();

                reader = new BufferedReader(new InputStreamReader(stream));

                StringBuffer buffer = new StringBuffer();

                String value = "";

                while ((value = reader.readLine()) != null) {
                    buffer.append(value);
                    //System.out.println(value);
                }

                return buffer.toString();

            } catch (MalformedURLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (connection != null)
                    connection.disconnect();

                try {
                    if (reader != null)
                        reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return null;
        }

        @Override
        protected void onPostExecute(String result) {
            super.onPostExecute(result);

            if (result != null) {

                Integer light_value = Integer.valueOf(result);

                if (light_value >= 3000)
                {
                    img.setImageResource(R.drawable.sun3);
                }
                else if (light_value < 3000)
                {
                    img.setImageResource(R.drawable.cloud2);
                }
            }

        }

    }


    public class HttpRequestLed1 extends AsyncTask<URL, String, String> {

        @Override
        protected String doInBackground(URL... params) {

            HttpURLConnection connection = null;
            BufferedReader reader = null;

            try {

                URL url = new URL("http://192.168.1.69/led1");
                connection = (HttpURLConnection) url.openConnection();
                connection.connect();

                InputStream stream = connection.getInputStream();

                reader = new BufferedReader(new InputStreamReader(stream));

                StringBuffer buffer = new StringBuffer();

                String value = "";

                while ((value = reader.readLine()) != null)
                {
                    buffer.append(value);
                    System.out.println(value);
                }

                return buffer.toString();

            } catch (MalformedURLException e) {
                e.printStackTrace();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
             finally {
                if (connection != null)
                    connection.disconnect();
            }
            return null;
        }

    }


    public class HttpRequestLed2 extends AsyncTask<URL, String, String> {

        @Override
        protected String doInBackground(URL... params) {

            HttpURLConnection connection = null;
            BufferedReader reader = null;

            try {

                URL url = new URL("http://192.168.1.69/led2");
                connection = (HttpURLConnection) url.openConnection();
                connection.connect();

                InputStream stream = connection.getInputStream();

                reader = new BufferedReader(new InputStreamReader(stream));

                StringBuffer buffer = new StringBuffer();

                String value = "";

                while ((value = reader.readLine()) != null)
                {
                    buffer.append(value);
                    System.out.println(value);
                }

                return buffer.toString();

            } catch (MalformedURLException e) {
                e.printStackTrace();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            finally {
                if (connection != null)
                    connection.disconnect();
            }
            return null;
        }

    }
}









