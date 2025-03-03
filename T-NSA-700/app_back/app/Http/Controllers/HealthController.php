<?php

namespace App\Http\Controllers;

use DB;
use Log;
use Illuminate\Http\Request;
use App\Models\ChatMessages;

class HealthController extends Controller
{

    public function index() {
        $output = [
            'hostname' => gethostname(),
        ];
        
        $date_begin = microtime(true);

        try {
            DB::connection()->getPdo();
            $output['mysql'] = 'healthy';

            try {
                $output['chat_messages_count'] = ChatMessages::all()->count();
                $output['mysql_migrations'] = 'healthy';
            } catch (\Exception $e) {
                Log::error("Failed to fetch chat messages");
                Log::error($e);
                $output['mysql_migrations'] = 'unhealthy';
            }
        } catch (\Exception $e) {
            Log::error("Failed to connect to database");
            Log::error($e);
            $output['mysql'] = 'unhealthy';
        }

        $date_end = microtime(true);
        $output['response_time_ms'] = round(($date_end - $date_begin) * 1000, 1);

        return response()->json($output);
    }

}
