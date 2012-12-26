package com.example.voicetest;

import java.util.ArrayList;
import java.util.Iterator;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.speech.RecognizerIntent;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;



public class MainActivity extends Activity 
{
	
	ListView lv;
	Button btSpeak;
	TextView tvResult;
	protected int check=111;
	
	String[] cmds={"book","back","left","right","stop"};
	

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        

        
            setupViews();
            
    }// end of onCreate()...

    private void setupViews() 
    {
	
    	//lv=(ListView)findViewById(R.id.lv_voice_result);
    	tvResult=(TextView)findViewById(R.id.tv_result);
    	btSpeak=(Button)findViewById(R.id.bt_speak);
    	
    	btSpeak.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) 
			{
				Intent voiceIntent=new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
				voiceIntent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL,RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
				voiceIntent.putExtra(RecognizerIntent.EXTRA_PROMPT,"Speak Up");
				startActivityForResult(voiceIntent, check);
				// check => request code...
				
			}
		});
		
    	
    	
		
	}// end of setupViews()...
    
	protected void onActivityResult(int requestCode, int resultCode, Intent data) 
	{
		if(requestCode==check && resultCode==RESULT_OK)
		{
			

			ArrayList<String> results = data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
			
			Iterator it=results.iterator();
			int count=0;
			
			while(it.hasNext())
			{
				
				String temp=it.next().toString();
				
				for(int i=0;i<cmds.length;i++)
				{
					if(temp.equalsIgnoreCase(cmds[i]))
						{
							tvResult.setText(temp);
							break;
						}
					
				}// end of for...
				
				count++;
				
				if(count>8)
					break;
				
				
			}// end of while...
			
						
		}
		
		super.onActivityResult(requestCode, resultCode, data);
	}

	@Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
}
