package com.example.voicetest;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class BaseActivity extends Activity 
{
	
	Button btnClickMe;
	
	public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.base_act);
        
        

        
            setupViews();
            
    }// end of onCreate()...

	private void setupViews()
	{
		btnClickMe=(Button)findViewById(R.id.base_btn);
		
		btnClickMe.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View arg0) 
			{
				Intent openMain= new Intent(BaseActivity.this,MainActivity.class);
				
				
				
				
				startActivity(openMain);				
				//openMain.
				
			}
		});
		
		
	}

	
	

}
