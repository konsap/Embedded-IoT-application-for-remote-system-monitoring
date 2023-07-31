//package com.example.proigmena_themata;
//
//import android.os.AsyncTask;
////
////import java.io.BufferedReader;
////import java.io.IOException;
////import java.io.InputStream;
////import java.io.InputStreamReader;
////import java.net.HttpURLConnection;
////import java.net.MalformedURLException;
////import java.net.URL;
////
////
////
////public class HttpRequest extends AsyncTask<URL, String, String> {
////
////    @Override
////    protected String doInBackground(URL... params) {
////
////        HttpURLConnection connection = null;
////        BufferedReader reader = null;
////
////        try {
////            URL url = new URL("http://192.168.1.69");
////            connection = (HttpURLConnection) url.openConnection();
////            connection.connect();
////
////            InputStream stream = connection.getInputStream();
////
////            reader = new BufferedReader(new InputStreamReader(stream));
////
////            StringBuffer buffer = new StringBuffer();
////
////            String value = "";
////
////            while ((value = reader.readLine()) != null) {
////                buffer.append(value);
////                //System.out.println(value);
////            }
////
////            return buffer.toString();
////
////        } catch (MalformedURLException e) {
////            e.printStackTrace();
////        } catch (IOException e) {
////            e.printStackTrace();
////        } finally {
////            if (connection != null)
////                connection.disconnect();
////
////            try {
////                if (reader != null)
////                    reader.close();
////            } catch (IOException e) {
////                e.printStackTrace();
////            }
////        }
////        return null;
////    }
////
////    @Override
////    protected void onPostExecute(String result) {
////        super.onPostExecute(result);
////        data.SetText(result);
////}
////
////}
