<?php

namespace App\Http\Controllers;

use DB;
use Log;
use Illuminate\Http\Request;
use App\Models\ChatMessages;

class ChatController extends Controller
{

    public function list() {
        try {
            $results = ChatMessages::all()->sortByDesc('created_at');
        } catch (\Exception $e) {
            Log::error("Cannot fetch chat messages");
            Log::error($e);
            abort(500);
        }
        // return response($results)->json();
        return response()->json($results->values());
    }

    public function create(Request $request) {
        $input = $request->validate([
            'username' => 'required|string|min:3|max:255',
            'message' => 'required|string|min:1',
        ]);

        try {
            $cm = ChatMessages::create([
                'username' => $input['username'],
                'message' => $input['message'],
            ]);
        } catch (\Exception $e) {
            Log::error("Cannot fetch chat messages");
            Log::error($e);
            abort(500);
        }

        return response()->json(['status' => 'ok', 'chat_message' => $cm]);
    }

}
